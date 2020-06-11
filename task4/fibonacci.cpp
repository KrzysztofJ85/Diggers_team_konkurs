#include "fibonacci.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

size_t fibonacci1(size_t sequence) {
    const double sqrt5 = std::sqrt(5);
    const double n = (1 + sqrt5) / 2;
    return (int)(std::pow(n, sequence) / sqrt5 + 0.5);
}

size_t fibonacci2(size_t sequence) {
    if (sequence < 2) {
        return sequence;
    }

    std::vector<size_t> values(sequence+1);
    values[1] = 1;
    values[2] = 1;

    std::transform(values.begin(), values.end() - 2,
        values.begin() + 1, values.begin() + 2,
        std::plus<>() );

    return values.back();
}

int main() {
    const int N = 15;

    std::cout << "\nfibonacci1\n";
    for (size_t k = 0; k <= N; k++) {
      std::cout << k << ": " << fibonacci1(k) << "\n";
    }

    std::cout << "\nfibonacci2\n";
    for (size_t k = 0; k <= N; k++) {
      std::cout << k << ": " << fibonacci2(k) << "\n";
    }

    return 0;
}
