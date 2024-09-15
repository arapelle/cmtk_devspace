include(cmtk/CMTKNS_CppLibraryExamples)
include(cmtk/Spdlog)

CMTKNS_add_cpp_library_basic_examples(${PROJECT_TARGET_NAME}
    SOURCES
        cpp_util_basic_example.cpp
)

CMTKNS_add_cpp_library_example(cpp_util_example ${PROJECT_TARGET_NAME} 
    SOURCES
        cpp_util_example.cpp
)
set_SPDLOG_ACTIVE_LEVEL_ifndef(cpp_util_example)
target_SPDLOG_ACTIVE_LEVEL_definition(cpp_util_example)
