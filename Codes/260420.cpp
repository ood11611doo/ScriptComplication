#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    for (int i = 0; i < citations.size(); i++) {
        int curCounts = 0;
        for (int j = 0; j < citations.size(); j++) {
            if (citations[j] >= citations[i]) {
                curCounts++;
            }
        }
        if (citations[i] >= curCounts && curCounts > answer) {
            answer = curCounts;
        }
    }
    return answer;
}