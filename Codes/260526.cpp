#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> matrix(rows + 1, vector<int>(columns + 1));
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            matrix[i][j] = (i - 1) * columns + j;
        }
    }
    for (const auto& q : queries) {
        int x1 = q[0], y1 = q[1], x2 = q[2], y2 = q[3];
        
        int temp = matrix[x1][y1];
        int min_val = temp;

        for (int i = x1; i < x2; i++) {
            matrix[i][y1] = matrix[i + 1][y1];
            min_val = min(min_val, matrix[i][y1]);
        }

        for (int i = y1; i < y2; i++) {
            matrix[x2][i] = matrix[x2][i + 1];
            min_val = min(min_val, matrix[x2][i]);
        }

        for (int i = x2; i > x1; i--) {
            matrix[i][y2] = matrix[i - 1][y2];
            min_val = min(min_val, matrix[i][y2]);
        }

        for (int i = y2; i > y1; i--) {
            matrix[x1][i] = matrix[x1][i - 1];
            min_val = min(min_val, matrix[x1][i]);
        }

        matrix[x1][y1 + 1] = temp;
        answer.push_back(min_val);
    }
    return answer;
}