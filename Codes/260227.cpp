#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    answer.push_back(-1);
    for (int i = 1; i < s.size(); i++) {
        int finder = -1;
        for (int j = i - 1; j >= 0; j--) {
            if (s[i] == s[j]) {
                finder = i - j;
                break;
            }
        }
        answer.push_back(finder);
    }
    return answer;
}