#include <algorithm>
#include <iostream>
#include <numeric>
#include <regex>
#include <string>
#include <vector>

std::string RemoveRepetition(const std::string& text) {
    std::regex pattern("[\\s]+");
    std::sregex_token_iterator reg_beg(text.begin(), text.end(), pattern, -1);
    std::sregex_token_iterator reg_end;

    std::vector<std::string> words;
    std::copy(reg_beg, reg_end, std::back_inserter(words));

    auto it = std::unique(words.begin(), words.end());
    words.resize(std::distance(words.begin(), it));

    std::string result = std::accumulate(words.begin(), words.end(), std::string(),
        [](const std::string& lhs, const std::string& rhs) { return lhs.empty() ? rhs : lhs + ' ' + rhs; }
    );

    return result;
}

int main()
{
    std::vector<std::string > data = {
        "Ala ma ma kota, a kot ma ma Ale Ale",
        "tulipan roza roza stokrotka gozdzik gozdzik roza tulipan chryzantemy zlociste ",
        "truskawka porzeczka malina malina porzeczka porzeczka wisnia jablko wisnia wisnia brzoskwinia"
    };

    for (const auto & text : data) {
        std::cout << text << "\n" << RemoveRepetition(text) << "\n";
    }

    return 0;
}
