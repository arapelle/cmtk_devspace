include(cmtk/Spdlog)

add_cpp_library_basic_examples(SHARED ${PROJECT_NAME}
                         STATIC ${PROJECT_NAME}-static
                         SOURCES cpp_util_basic_example.cpp)

add_cpp_library_example(cpp_util_example
    SHARED ${PROJECT_NAME}
    STATIC ${PROJECT_NAME}-static
    SOURCES cpp_util_example.cpp)
set_SPDLOG_ACTIVE_LEVEL_ifndef(cpp_util_example)
target_SPDLOG_ACTIVE_LEVEL_definition(cpp_util_example)
