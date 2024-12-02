#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
#include<cmath>

int main(int argc, char const *argv[])
{
    int result = 0;
    std::string line;
    std::ifstream file("day2.txt");
    if(!file.is_open()) return 1;

    while(std::getline(file, line)){
        if(line.empty()) break;

        std::stringstream ss(line);
        std::vector<int> row;
        int number;

        while(ss >> number){
            row.push_back(number);
        }

        bool is_valid = true;
        bool increasing = row[1] > row[0];
        for(int i = 1; i < row.size(); ++i){
            int diffrence = row[i] - row[i - 1];
            if(std::abs(diffrence) < 1 || std::abs(diffrence) > 3) is_valid = false;
            if((increasing && diffrence < 0) || (!increasing && diffrence > 0)) is_valid = false;
        }

        if(is_valid) result++;
    }

    std::cout << result << std::endl;

    file.close();

    return 0;
}
