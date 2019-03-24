#include "roverdispatcher.h"
#include <unistd.h>
#include <iostream>
int main()
{
    std::vector<std::string> input;
    std::string line;
    if (isatty(STDIN_FILENO)) {
        std::cout << "Please enter grid vertex e.g. x y: ";
        while (1) {
            std::getline(std::cin, line);
            input.push_back(line);
            std::cout << "Please enter Rover e.g. x y H (enter to dispatch): ";
            std::getline(std::cin, line);
            if (line.empty())
                break;
            else
                input.push_back(line);
            std::cout << "Please enter Rover instructions: ";
        }
    } else {
        std::string line;
        while (std::getline(std::cin, line))
            input.push_back(line);
    }

    try {
        roverdispatcher dispatcher;
        dispatcher.parseInput(input);
        dispatcher.dispatch();
        std::cout << dispatcher.renderView();
    }
    catch (const char* e) { std::cout << e << std::endl; }
    catch (std::string &e) {std::cout << e << std::endl;}

return 0;
}
