#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> snails(n, vector<int>(n, 0));
    int fillX = 0;
    int fillY = -1;
    int fillNum = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (i % 3 == 0) {
                fillY++;
            } else if (i % 3 == 1) {
                fillX++;
            } else {
                fillY--;
                fillX--;
            }
            snails[fillY][fillX] = fillNum++;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            answer.push_back(snails[i][j]);
        }
    }
    return answer;
}