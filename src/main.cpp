#include <iostream>
#include <vector>
#include <string>
#include "service/Engine.h"
#include <drogon/drogon.h>

void test()
{
    std::vector<std::string> data = {
        "empty 133 29 20 32",
        "empty 132 30 29 93",
        "empty 133 32 29 94",

        "empty 133 29 20 32",
        "empty 134 29 20 32",
        "empty 135 29 20 32",
        "empty 136 29 20 32",

        "empty 12 10 20 20",
        "empty 10 12 20 20",
        "empty 10 10 20 20",
        "empty 10 10 20 20",
    };

    service::Engine engine;

    for(auto & entry : data)
    {
        engine.step(entry);
        std::cout << ">> " << entry << std::endl;
        for(const auto & entity : engine.entities)
        {
            std::cout << entity.name << "  " << entity.id << " #" << entity.path.snapshots.size() << std::endl;
        }
        std::cout << "---" << std::endl;
    }

    std::cout << "hello world!" << std::endl;
}

using namespace drogon;

int main(int argc, char** argv) {
    constexpr auto port = 9000;
    try
    {
        std::cout << "Starting kinet at http://localhost:" << port << std::endl;
        app().addListener("0.0.0.0", port).run();
    } catch (const std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
