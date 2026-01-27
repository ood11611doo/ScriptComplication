#include <string>
#include <vector>

using namespace std;

vector<int> answer;

void checkSquare(const vector<vector<int>>& arr, int x, int y, int size) {
    int checkNum = arr[x][y];
    if (size == 1) {
        if (checkNum == 0) answer[0]++;
        else answer[1]++;
        return;
    }
    
    bool checkSame = true;
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (arr[i][j] != checkNum) {
                checkSame = false;
                break;
            }
        }
        if (!checkSame) {
            break;
        }
    }
    
    if (checkSame) {
        if (checkNum == 0) answer[0]++;
        else answer[1]++;
        return;
    }
    
    int decSized = size / 2;
    checkSquare(arr, x, y, decSized);
    checkSquare(arr, x + decSized, y, decSized);
    checkSquare(arr, x, y + decSized, decSized);
    checkSquare(arr, x + decSized, y + decSized, decSized);
}

vector<int> solution(vector<vector<int>> arr) {
    answer.clear();
    answer = { 0, 0 };
    checkSquare(arr, 0, 0, arr.size());
    return answer;
}