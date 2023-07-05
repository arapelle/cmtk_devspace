#include <iostream>
#include <resorice/resorice.hpp>
#include <resorice/version.hpp>

int main()
{
    std::cout << RESORICE_VERSION << std::endl;
    std::cout << resorice::find_serialized_resource("RESORICE:/text/tale.txt")->size() << std::endl;
    return EXIT_SUCCESS;
}
