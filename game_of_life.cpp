#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <thread>
#include <unistd.h>
#include <term.h>
#include <string>

// g++ -std=c++11 -lcurses game_of_life.cpp

void ClearScreen() {
    if (!cur_term) {
        int result;
        setupterm(nullptr, STDOUT_FILENO, &result);
        if (result <= 0) return;
    }
    std::string str = "clear";
    char* chars;
    strcpy(chars, str.c_str());
    putp(tigetstr(chars));
}

class Universe {
public:
    int iHeight;
    int iWidth;
    std::vector<std::vector<int>> matrixWorld;
public:
    Universe(int h, int w) : iHeight(h), iWidth(w) {
        size_t seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine generator (seed);
        std::uniform_int_distribution<int> distribution(0,1);
        for (size_t r = 0; r < h; ++r) {
            std::vector<int> vec;
            for (size_t c = 0; c < w; ++c) {
                vec.push_back(distribution(generator));
            }
            matrixWorld.push_back(vec);
        }
    }

    void showWorld() {
        std::cout << "matrix world -->" << std::endl;
        for (size_t r = 0; r < iHeight; ++r) {
            for (size_t c = 0; c < iWidth; ++c) {
                std::cout << (matrixWorld[r][c]==1 ? "*" : "-") << "  ";
            }
            std::cout << std::endl << std::endl;
        }
    }

    // status 0: death -> death
    // status 1: live -> live
    // status 2: live -> death
    // status 3: death -> live 
    void updateWorld() {
        int m = matrixWorld.size(), n = m ? matrixWorld[0].size() : 0;
        int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cnt = 0;
                for (int k = 0; k < 8; ++k) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x >= 0 && x < m && y >= 0 && y < n && (matrixWorld[x][y] == 1 || matrixWorld[x][y] == 2)) {
                        ++cnt;
                    }
                }
                if (matrixWorld[i][j] && (cnt < 2 || cnt > 3)) {
                    matrixWorld[i][j] = 2;
                } else if (!matrixWorld[i][j] && cnt == 3) {
                    matrixWorld[i][j] = 3;
                }
            }
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                matrixWorld[i][j] %= 2;
            }
        }
    }
};

int main() {
    Universe universe(4, 5);
    for (size_t t = 0; t < 10; ++t) {
        ClearScreen();
        universe.showWorld();
        universe.updateWorld();
        universe.showWorld();
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    return 0;
}
