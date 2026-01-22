#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(int x, int y, int n) {
    int answer = 0;
    vector<int> calcs(y + 1, 1000001);
    calcs[x] = 0;
    for (int i = x; i < y + 1; i++) {
        if (calcs[i] == 1000001) {
            continue;
        }
        
        if (i + n <= y) {
            calcs[i + n] = min(calcs[i + n], calcs[i] + 1);
        }
        if (i * 2 <= y) {
            calcs[i * 2] = min(calcs[i * 2], calcs[i] + 1);
        }
        if (i * 3 <= y) {
            calcs[i * 3] = min(calcs[i * 3], calcs[i] + 1);
        }
    }
    
    if (calcs[y] == 1000001) {
        answer = -1;
    } else {
        answer = calcs[y];
    }
    return answer;
}