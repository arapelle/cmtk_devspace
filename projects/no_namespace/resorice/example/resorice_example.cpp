#include <iostream>
#include <resorice/find_serialized_resource.hpp>
#include <resorice/version.hpp>

int main()
{
    std::cout << resorice::find_serialized_resource("RESORICE:/text/tale.txt")->size() << std::endl;
    return EXIT_SUCCESS;
}
