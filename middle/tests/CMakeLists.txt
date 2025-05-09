set(FRONTEND_SOURCES
        ../../frontend/utils/ast_utils.cpp
        ../../frontend/semantic.cpp
        ../../frontend/VtBaseListener.cpp
        ../../frontend/VtBaseVisitor.cpp
        ../../frontend/VtLexer.cpp
        ../../frontend/VtParser.cpp
        ../../frontend/VtListener.cpp
        ../../frontend/VtVisitor.cpp
)

set(MIDDLE_SOURCES
        ../ir_generator.cpp
        ../utils/ir_utils.cpp
)

add_executable(test_ir_generator
        test_ir_generator.cpp
        ${FRONTEND_SOURCES}
        ${MIDDLE_SOURCES}
)

foreach (target IN ITEMS test_ir_generator)
    target_include_directories(${target} PRIVATE /usr/local/include/antlr4-runtime)
    target_link_libraries(${target}
            gtest
            gtest_main
            antlr4-runtime
    )

    if (APPLE)
        target_link_options(${target} PRIVATE "-Wl,-rpath,/usr/local/lib")
    endif ()
endforeach ()

include(GoogleTest)
gtest_discover_tests(test_ir_generator)
