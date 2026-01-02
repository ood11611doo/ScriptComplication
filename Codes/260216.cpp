#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int oddChecker = 0;
    for (const char& charGet : s) {
        if (charGet == ' ') {
            answer += charGet;
            oddChecker = 0;
            continue;
        }
        
        if (oddChecker % 2 == 0) {
            if (charGet >= 'a' && charGet <= 'z') {
                answer += charGet - ('a' - 'A');
            } else {
                answer += charGet;
            }
        } else {
            if (charGet >= 'A' && charGet <= 'Z') {
                answer += charGet + ('a' - 'A');
            } else {
                answer += charGet;
            }
        }
        
        oddChecker++;
    }
    return answer;
}