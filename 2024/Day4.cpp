#include<iostream>
#include<vector>
#include<string>
#include<fstream>

const int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

bool isValid(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

bool find(std::vector<std::string> grid, int x, int y, int dir, std::string word){
    int rows = grid.size();
    int cols = grid[0].size();
    for (int i = 0; i < word.size(); ++i) {
        int nx = x + i * dx[dir];
        int ny = y + i * dy[dir];
        if (!isValid(nx, ny, rows, cols) || grid[nx][ny] != word[i]) {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    std::ifstream file("day4.txt");
    if(!file.is_open()) return 1;
    
    std::string line;
    std::vector<std::string> grid;
    while(file >> line){
        grid.push_back(line);
    }

    int rows = grid.size();
    int columns = grid[0].size();
    int count = 0;

    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j){
            for(int k = 0; k < 8; ++k){
                if(find(grid, i, j, k, "XMAS"))
                    count++;
            }
        }
    }

    std::cout << count << std::endl;

    file.close();
    return 0;
}
