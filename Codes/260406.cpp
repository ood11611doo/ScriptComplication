#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool upperCased = true;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            upperCased = true;
            continue;
        }
        
        if (!upperCased) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = (s[i] - 'A') + 'a';
            }
            continue;
        }
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = (s[i] - 'a') + 'A';
        }
        upperCased = false;
    }
    answer = s;
    return answer;
}