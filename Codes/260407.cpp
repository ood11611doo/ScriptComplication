#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int workCount = 0;
    int removeCount = 0;
    while (s != "1") {
        workCount++;
        int lengthGet = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                lengthGet++;
            } else if (s[i] == '0') {
                removeCount++;
            }
        }
        string newStr = "";
        while (lengthGet >= 1) {
            if (lengthGet % 2 == 1) {
                newStr += "1";
            } else {
                newStr += "0";
            }
            lengthGet /= 2;
        }
        s = newStr;
    }
    answer.push_back(workCount);
    answer.push_back(removeCount);
    return answer;
}