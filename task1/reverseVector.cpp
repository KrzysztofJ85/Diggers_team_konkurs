#include "reverseVector.hpp"

#include <algorithm>
#include <iostream>

void print(std::vector<int>& vec) {
    for (const auto& el : vec) {
        std::cout << el << ' ';
    }
    std::cout << '\n';
}

std::vector<int> reverseSolutionOne(std::vector<int> vec) {
    std::reverse(vec.begin(), vec.end());

    return vec;
}

std::vector<int> reverseSolutionTwo(std::vector<int> vec) {
    std::vector<int> vec2(vec);
    std::copy(vec.rbegin(), vec.rend(), vec2.begin());
    return vec2;
}

std::vector<int> reverseSolutionThree(std::vector<int> vec) {
    std::vector<int> vec2(vec);
    std::copy_backward(vec.rbegin(), vec.rend(), vec2.end());
    return vec2;
}

std::vector<int> reverseSolutionFour(std::vector<int> vec) {
    std::vector<int> vec2(vec);
    std::move_backward(vec.rbegin(), vec.rend(), vec2.end());
    return vec2;
}

std::vector<int> reverseSolutionFive(std::vector<int> vec) {
    std::vector<int> vec2(vec.rbegin(), vec.rend());
    swap(vec2, vec);
    return vec;
}

std::vector<int> reverseSolutionSix(std::vector<int> vec) {
    std::transform(vec.begin(), vec.begin() + vec.size() / 2,
                   vec.rbegin(), vec.begin(),
                   [](int& x, int& y) {
                       std::swap(x, y);
                       return x;
                   });
    return vec;
}

std::vector<int> reverseSolutionSeven(std::vector<int> vec) {
    for (auto start = vec.begin(), end = std::prev(vec.end()); start < end; ++start, --end) {
        std::swap(*start, *end);
    }

    return vec;
}

int main() {
    print(vectorToReverse);
    auto reversedVector = reverseSolutionOne(vectorToReverse);
    print(reversedVector);
    reversedVector = reverseSolutionTwo(vectorToReverse);
    print(reversedVector);
    reversedVector = reverseSolutionThree(vectorToReverse);
    print(reversedVector);
    reversedVector = reverseSolutionFour(vectorToReverse);
    print(reversedVector);
    reversedVector = reverseSolutionFive(vectorToReverse);
    print(reversedVector);
    reversedVector = reverseSolutionSix(vectorToReverse);
    print(reversedVector);
    reversedVector = reverseSolutionSeven(vectorToReverse);
    print(reversedVector);

    return 0;
}