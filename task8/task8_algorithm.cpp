#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

void PrintStarTree(size_t rows)
{
    if (rows > 0) {
        size_t space = rows - 1, count = rows;
        std::generate_n(std::ostream_iterator<std::string>(std::cout, "\n"), rows,
            [&space, &count]() {
                size_t star = count++ - space;
                return std::string(space--, ' ') + std::string(star, '*');
            } );
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
