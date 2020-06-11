#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>

std::string RemoveRepetition(const std::string& text) {
    std::istringstream iss(text);
    std::vector<std::string> words(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());

    auto it = std::unique(words.begin(), words.end());
    words.resize(std::distance(words.begin(), it));

    std::ostringstream oss;
    std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(oss, " "));

    return oss.str();
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
