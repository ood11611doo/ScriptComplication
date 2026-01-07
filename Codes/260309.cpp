#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    vector<int> sorted(score);
    sort(sorted.begin(), sorted.end());
    int repeatTime = sorted.size();
    repeatTime /= m;
    for (int i = 0; i < repeatTime; i++) {
        int smallest = k;
        for (int j = 0; j < m; j++) {
            int popGet = sorted[sorted.size() - 1];
            if (popGet < smallest) {
                smallest = popGet;
            }
            sorted.pop_back();
        }
        smallest *= m;
        answer += smallest;
    }
    return answer;
}