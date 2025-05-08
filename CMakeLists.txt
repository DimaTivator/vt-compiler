cmake_minimum_required(VERSION 3.16)
project(vt-compiler)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)

include_directories(/usr/local/include/antlr4-runtime)
link_directories(/usr/local/lib)

add_executable(vt_compiler
        main.cpp
        frontend/ast_builder.cpp
        frontend/utils/ast_utils.cpp
        frontend/semantic.cpp
        frontend/VtBaseListener.cpp
        frontend/VtBaseVisitor.cpp
        frontend/VtLexer.cpp
        frontend/VtParser.cpp
        frontend/VtListener.cpp
        frontend/VtVisitor.cpp
        middle/ir_generator.cpp
        middle/utils/ir_utils.cpp
)

target_link_libraries(vt_compiler antlr4-runtime)

if(APPLE)
    target_link_options(vt_compiler PRIVATE
            "-Wl,-rpath,/usr/local/lib"
    )
endif()

add_subdirectory(external/googletest)
enable_testing()
add_subdirectory(frontend/tests)
add_subdirectory(middle/tests)
