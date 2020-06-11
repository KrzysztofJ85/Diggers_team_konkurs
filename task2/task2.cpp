#include "task2.hpp"

#include <algorithm>
#include <iostream>

void print1(const std::vector<int>& vec) {
    std::cout << "print1:\n";
    std::for_each(vec.cbegin(), vec.cend(),
                  [](int v) {
                      std::cout << v << ' ';
                  });
    std::cout << '\n';
}

void print2(const std::vector<int>& vec) {
    std::cout << "print2:\n";
    std::all_of(vec.cbegin(), vec.cend(),
                [](int v) {
                    std::cout << v << ' ';
                    return true;
                });
    std::cout << '\n';
}

void print3(const std::vector<int>& vec) {
    std::cout << "print3:\n";
    std::any_of(vec.cbegin(), vec.cend(),
                [](int v) {
                    std::cout << v << ' ';
                    return false;
                });
    std::cout << '\n';
}

void print4(const std::vector<int>& vec) {
    std::cout << "print4:\n";
    std::none_of(vec.cbegin(), vec.cend(),
                 [](int v) {
                     std::cout << v << ' ';
                     return false;
                 });
    std::cout << '\n';
}

void print5(const std::vector<int>& vec) {
    std::cout << "print5:\n";
    std::for_each_n(vec.cbegin(), vec.size(),
                    [](int v) {
                        std::cout << v << ' ';
                        return true;
                    });
    std::cout << '\n';
}

void print6(const std::vector<int>& vec) {
    std::cout << "print6:\n";
    for (auto& el : vec) {
        auto result = std::find(vec.begin(), vec.end(), el);
        if (result != vec.end()) {
            std::cout << el << ' ';
        }
    }
    std::cout << '\n';
}

void print7(const std::vector<int>& vec) {
    std::cout << "print7:\n";
    for (auto& el : vec) {
        std::cout << el << ' ';
    }
    std::cout << '\n';
}

int main() {
    print1(refVec);
    print2(refVec);
    print3(refVec);
    print4(refVec);
    print5(refVec);
    print6(refVec);
    print7(refVec);
    return 0;
}
