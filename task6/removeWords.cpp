#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <numeric>

#include <iostream>

#define istream std::istream_iterator<std::string>

std::string removeWords(const std::string& text){
    std::istringstream stext(text);
    std::vector<std::string> words(istream{stext}, istream());

    words.erase(std::remove_if(words.begin(), words.end(), 
        [](const std::string& word){
            return word.size() == 4 || word.size() == 6;
        }), words.end());
    
    return std::accumulate(std::next(words.begin()), words.end(), words[0],
        [](std::string lhs, std::string rhs) {return std::move(lhs) + ' ' + rhs;}); 
}

int main(){
    std::cout << removeWords("Ala ma koa.");
}