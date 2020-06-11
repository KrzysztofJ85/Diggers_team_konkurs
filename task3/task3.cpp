#include "task3.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

const std::string palindrom = "ala a ala";
const std::string not_palindrom = "ala ma kota";

void isPalindrome1(const std::string& str) {
    std::cout << "isPalindrome1:\n";
    if (std::equal(str.cbegin(), str.cbegin() + str.size() / 2, str.crbegin())) {
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
    std::reverse_copy(str.cbegin(), str.cend(), strcopy.begin());
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

void isPalindrome6(const std::string& str) {
    std::string strcopy;
    std::cout << "isPalindrome6:\n";
    std::copy(str.crbegin(), str.crend(), std::back_inserter(strcopy));
    if (strcopy == str) {
        std::cout << str << " is palindrome" << '\n';
    } else {
        std::cout << str << " is not palindrome" << '\n';
    }
    std::cout << '\n';
}

void isPalindrome7(const std::string& str) {
    std::string strcopy;
    std::cout << "isPalindrome7:\n";
    std::copy_if(str.crbegin(), str.crend(), std::back_inserter(strcopy), [](char c) { return true; });
    if (strcopy == str) {
        std::cout << str << " is palindrome" << '\n';
    } else {
        std::cout << str << " is not palindrome" << '\n';
    }
    std::cout << '\n';
}

void isPalindrome8(const std::string& str) {
    std::string strcopy;
    std::cout << "isPalindrome8:\n";
    std::copy_n(str.crbegin(), str.size(), std::back_inserter(strcopy));
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
    isPalindrome6(palindrom);
    isPalindrome6(not_palindrom);
    isPalindrome7(palindrom);
    isPalindrome7(not_palindrom);
    isPalindrome8(palindrom);
    isPalindrome8(not_palindrom);
    return 0;
}
