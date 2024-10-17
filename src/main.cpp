#include <iostream>
#include <vector>
#include <string>
#include <drogon/drogon.h>

int main(int argc, char** argv) {
    constexpr auto port = 9000;
    try
    {
         std::cout << "|/o._  __|_ \n"
            << "|\\|| |(/_|_ Tracking engine v1.0 is running at "
        << "http://localhost:" << port << std::endl;
        drogon::app().addListener("0.0.0.0", port).run();
    } catch (const std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
