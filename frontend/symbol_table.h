#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace vt::sem {

enum class Type { INT, STRING, UNKNOWN };

inline Type ParseType(const std::string& str) {
    if (str == "int") {
        return Type::INT;
    }
    if (str == "string") {
        return Type::STRING;
    }
    return Type::UNKNOWN;
}

inline std::string TypeToString(Type type) {
    switch (type) {
        case Type::INT:
            return "int";
        case Type::STRING:
            return "string";
        default:
            return "unknown";
    }
}

struct Symbol {
    Type type;
    // TODO extend with other attributes
};

class Scope {
public:
    explicit Scope(std::shared_ptr<Scope> parent = nullptr)
        : parent_(std::move(parent)) {}

    bool Declare(const std::string& name, Symbol symbol) {
        if (symbols_table_.contains(name)) {
            return false;
        }
        symbols_table_[name] = symbol;
        return true;
    }

    Symbol* Lookup(const std::string& name) {
        auto it = symbols_table_.find(name);
        if (it != symbols_table_.end()) {
            return &it->second;
        }
        if (parent_ != nullptr) {
            return parent_->Lookup(name);
        }
        return nullptr;
    }

    [[nodiscard]] std::shared_ptr<Scope> Parent() const { return parent_; }

private:
    std::unordered_map<std::string, Symbol> symbols_table_;
    std::shared_ptr<Scope> parent_;
};

}  // namespace vt::sem
