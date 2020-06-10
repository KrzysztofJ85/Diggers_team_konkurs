#include "task3.hpp"

#include <algorithm>
#include <iostream>

const std::string palindrom = "ala a ala";
const std::string not_palindrom = "ala ma kota";

void isPalindrome1(const std::string& str) {
    std::cout << "isPalindrome1:\n";
    if (std::equal(str.begin(), str.begin() + str.size() / 2, str.rbegin())) {
        std::cout << str << " is palindrome" << '\n';
    } else {
        std::cout << str << " is not palindrome" << '\n';
    }
    std::cout << '\n';
}

void isPalindrome2(const std::string& str) {
    std::cout << "isPalindrome2:\n";
    std::string strcopy = str;
    std::reverse(strcopy.begin(), strcopy.end());
    if (strcopy == str) {
        std::cout << str << " is palindrome" << '\n';
    } else {
        std::cout << str << " is not palindrome" << '\n';
    }
    std::cout << '\n';
}

void isPalindrome3(const std::string& str) {
    std::cout << "isPalindrome3:\n";
    std::string strcopy = str;
    std::reverse_copy(str.begin(), str.end(), strcopy.begin());
    if (strcopy == str) {
        std::cout << str << " is palindrome" << '\n';
    } else {
        std::cout << str << " is not palindrome" << '\n';
    }
    std::cout << '\n';
}

void isPalindrome4(const std::string& str) {
    std::string strcopy = str;
    std::cout << "isPalindrome4:\n";
    for (auto it1 = strcopy.begin(), it2 = std::prev(strcopy.end()); it1 != strcopy.end(); ++it1, --it2) {
        if ((it1 - strcopy.begin()) < str.size() / 2) {
            std::swap(*it1, *it2);
        }
    }
    if (strcopy == str) {
        std::cout << str << " is palindrome" << '\n';
    } else {
        std::cout << str << " is not palindrome" << '\n';
    }
    std::cout << '\n';
}

void isPalindrome5(const std::string& str) {
    std::string strcopy = str;
    std::cout << "isPalindrome5:\n";
    for (auto it1 = strcopy.begin(), it2 = std::prev(strcopy.end()); it1 != strcopy.end(); ++it1, --it2) {
        if ((it1 - strcopy.begin()) < str.size() / 2) {
            std::iter_swap(it1, it2);
        }
    }
    if (strcopy == str) {
        std::cout << str << " is palindrome" << '\n';
    } else {
        std::cout << str << " is not palindrome" << '\n';
    }
    std::cout << '\n';
}

int main() {
    isPalindrome1(palindrom);
    isPalindrome1(not_palindrom);
    isPalindrome2(palindrom);
    isPalindrome2(not_palindrom);
    isPalindrome3(palindrom);
    isPalindrome3(not_palindrom);
    isPalindrome4(palindrom);
    isPalindrome4(not_palindrom);
    isPalindrome5(palindrom);
    isPalindrome5(not_palindrom);
    return 0;
}
