#include "fibonacci.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>

int fibonacci(int sequence) {
    const double sqrt5 = std::sqrt(5);
    const double n = (1 + sqrt5) / 2;
    return (int)(std::pow(n, sequence) / sqrt5 + 0.5);
}

int main() {
      std::cout << fibonacci(19) << "\n";

    return 0;
}
