#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

bool isValidUpdate(const vector<int>& update, const unordered_map<int, unordered_set<int>>& rules) {
    unordered_map<int, int> indexMap;
    for (int i = 0; i < update.size(); ++i) {
        indexMap[update[i]] = i;
    }

    for (const auto& [X, YSet] : rules) {
        if (indexMap.find(X) != indexMap.end()) {
            for (int Y : YSet) {
                if (indexMap.find(Y) != indexMap.end() && indexMap[X] >= indexMap[Y]) {
                    return false; 
                }
            }
        }
    }
    return true;
}

int main() {
    string line;
    unordered_map<int, unordered_set<int>> rules;
    vector<vector<int>> updates;

    ifstream inputFile("day5.txt");
    if (!inputFile) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    while (getline(inputFile, line) && !line.empty()) {
        vector<string> parts = split(line, '|');
        int X = stoi(parts[0]);
        int Y = stoi(parts[1]);
        rules[X].insert(Y);
    }

    while (getline(inputFile, line) && !line.empty()) {
        vector<string> parts = split(line, ',');
        vector<int> update;
        for (const string& p : parts) {
            update.push_back(stoi(p));
        }
        updates.push_back(update);
    }

    inputFile.close();

    int middleSum = 0;
    for (const vector<int>& update : updates) {
        if (isValidUpdate(update, rules)) {
            int middleIndex = update.size() / 2;
            middleSum += update[middleIndex];
        }
    }

    cout << middleSum << endl;

    return 0;
}