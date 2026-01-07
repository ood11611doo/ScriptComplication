#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    vector<int> secDec(section);
    while (secDec.size() > 0) {
        int minNum = secDec[0];
        for (int i = 0; i < m; i++) {
            int removeNum = minNum + i;
            auto finder = find(secDec.begin(), secDec.end(), removeNum);
            if (finder != secDec.end()) {
                secDec.erase(finder);
            }
        }
        answer++;
    }
    return answer;
}