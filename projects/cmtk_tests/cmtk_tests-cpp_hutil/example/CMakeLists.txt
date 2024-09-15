include(cmtk/CMTKNS_CppLibraryExamples)
include(cmtk/Spdlog)

set_SPDLOG_ACTIVE_LEVEL_ifndef(cpp_util_example)

CMTKNS_add_cpp_library_basic_examples(${PROJECT_NAME}
    SOURCES
        cpp_hutil_example.cpp
)
target_SPDLOG_ACTIVE_LEVEL_definition(cpp_hutil_example)
                         