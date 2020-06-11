#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool CheckAnagram(std::string lhs, std::string rhs) {
    if (lhs.size() != rhs.size()) {
        return false;
    }

    std::transform(lhs.begin(), lhs.end(), lhs.begin(),
        [](unsigned char c) { return std::tolower(c); }
    );

    std::transform(rhs.begin(), rhs.end(), rhs.begin(),
        [](unsigned char c) { return std::tolower(c); }
    );

    return std::is_permutation(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

int main()
{
    std::vector<std::pair<std::string, std::string> > data = {
        { "alegria", "galeria" },
        { "kapelusz", "paluszek" },
        { "stream", "master" },
        { "arbuz", "burza" },
        { "ekran", "ranek" },
        { "wektor", "wtorek" },
        { "nachodzi korba", "zachodni robak" },
        { "piesek", "kotek" },
        { "jablko", "gruszka" }
    };

    for (const auto & [lhs, rhs] : data) {
        std::cout << lhs << " | " << rhs << ( CheckAnagram(lhs, rhs) ? " are" : " are not" ) << " anagrams\n";
    }

    return 0;
}
