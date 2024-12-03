#include<iostream>
#include<string>
#include<fstream>
#include<regex>

int main(int argc, char const *argv[])
{
    int result = 0;
    std::ifstream file("day3.txt");
    if(!file.is_open()) return 1;
    std::string line;
    std::regex mul_regex("mul\\(([0-9]{1,3}),([0-9]{1,3})\\)");

    while(std::getline(file, line)){
        std::smatch mul_match;
        std::string::const_iterator begin = line.begin();
        
        while(std::regex_search(begin, line.cend(), mul_match, mul_regex)){
            result += std::stoi(mul_match[1]) * std::stoi(mul_match[2]);

            begin = mul_match.suffix().first;
        }
    }

    std::cout << result << std::endl; // 184511516
    file.close();

    return 0;
}
