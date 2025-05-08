set(FRONTEND_SOURCES
        ../utils/ast_utils.cpp
        ../semantic.cpp
        ../ast_builder.cpp
        ../VtBaseListener.cpp
        ../VtBaseVisitor.cpp
        ../VtLexer.cpp
        ../VtParser.cpp
        ../VtListener.cpp
        ../VtVisitor.cpp
)

add_executable(test_semantic
        test_semantic.cpp
        ${FRONTEND_SOURCES}
)

add_executable(test_ast_builder
        test_ast_builder.cpp
        ${FRONTEND_SOURCES}
)

foreach(target IN ITEMS test_ast_builder test_semantic)
    target_include_directories(${target} PRIVATE /usr/local/include/antlr4-runtime)
    target_link_libraries(${target}
            gtest
            gtest_main
            antlr4-runtime
    )

    if(APPLE)
        target_link_options(${target} PRIVATE "-Wl,-rpath,/usr/local/lib")
    endif()
endforeach()

include(GoogleTest)
gtest_discover_tests(test_ast_builder)
gtest_discover_tests(test_semantic)
