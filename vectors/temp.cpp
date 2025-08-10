#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int main()
{
    int length = 50000;
    std::string binary;
    binary.reserve(length); // reserve memory to avoid reallocation

    std::srand(std::time(0)); // seed RNG

    for (int i = 0; i < length; ++i)
    {
        binary += (std::rand() % 2 == 0 ? '0' : '1');
    }

    std::cout << binary << std::endl;
    return 0;
}
