#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <sstream>
#include <vector>

using istream = std::istream_iterator<std::string>;

std::string removeWords(const std::string& text) {
    std::istringstream stext(text);
    std::vector<std::string> words(istream{ stext }, istream());

    words.erase(std::remove_if(words.begin(), words.end(),
        [](const std::string& word) {
        size_t letters = std::count_if(word.begin(), word.end(),
            [](unsigned char c) { return std::isalpha(c); });
        return letters == 4 || letters == 6;
    }), words.end());

    return std::accumulate(std::next(words.begin()), words.end(), words[0],
        [](std::string lhs, std::string rhs) {return std::move(lhs) + ' ' + rhs; });
}

int main() {
    std::cout << removeWords("Ala ma kota a kot ma Ale, jednak to bylo dawno temu.");

    return 0;
}
