#include <cpp_texe/cpp_texe.hpp> 
#include <cpp_texe/version.hpp> 
#include <spdlog/spdlog.h>
#include <spdlog/sinks/ostream_sink.h>
#include <iostream>
#include <sstream>
#include <cstdlib>

inline namespace cmtk_tests
{
namespace cpp_texe
{

int main(int, char** argv)
{
    // https://stackoverflow.com/questions/66473052/how-can-i-read-spdlog-output-in-a-google-test
    
    int m = atoi(argv[1]);
    int x = atoi(argv[2]);
    int p = atoi(argv[3]);
    int res = operation(m, x, p);

    auto ostream_sink = std::make_shared<spdlog::sinks::ostream_sink_st>(std::cout);
    auto ostream_logger = std::make_shared<spdlog::logger>("gtest_logger", ostream_sink);
    ostream_logger->set_pattern("[%l] %v");
    ostream_logger->set_level(spdlog::level::level_enum(SPDLOG_ACTIVE_LEVEL));
    ostream_logger->info("operation-{}({}, {}, {}) = {}",
                CMTK_TESTS_CPP_TEXE_VERSION,
                m, x, p, res);

    return EXIT_SUCCESS;
}

}
}
