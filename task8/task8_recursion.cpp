#include <iostream>
#include <string>

void PrintRow(size_t space, size_t count) {
    std::cout << std::string(space, ' ') << std::string(count - space, '*') << "\n";
}

void PrintRows(size_t rows, size_t count) {
    if (rows > 0) {
        PrintRow(rows - 1, count);
        if (rows > 1) {
            PrintRows(rows - 1, count + 1);
        }
    }
}

void PrintStarTree(size_t rows){
    PrintRows(rows, rows);
}

int main()
{
    for (size_t k = 0; k <= 10; k++) {
        PrintStarTree(k);
        std::cout << std::string(20, '=') << "\n";
    }

    return 0;
}
