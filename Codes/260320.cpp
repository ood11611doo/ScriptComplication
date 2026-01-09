#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    while (s.size() > 0) {
        char recSame = s[0];
        int sameCount = 0;
        int otherCount = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == recSame)
                sameCount++;
            else
                otherCount++;
            if (sameCount == otherCount) {
                s = s.substr(i + 1, s.size() - (i + 1));
                break;
            }
            if (i == s.size() - 1) {
                s = "";
                break;
            }
        }
        answer++;
    }
    return answer;
}