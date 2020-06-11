#include <iostream>
#include <string>

void PrintStarTree(size_t rows) {
    for (size_t id = 1; id <= rows; id++) {
        for (size_t s = 1; s <= rows - id; ++s) {
            std::cout << " ";
        }
        for (size_t s = 0; s < 2*id - 1; ++s) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}

int main()
{
    for (size_t k = 0; k <= 10; k++) {
        PrintStarTree(k);
        std::cout << std::string(20, '=') << "\n";
    }

    return 0;
}
