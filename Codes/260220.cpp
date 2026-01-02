#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            answer += s[i];
            continue;
        }
        
        int countGet = s[i] + n;
        
        if (s[i] >= 'a' && s[i] <= 'z') {
            if (countGet < 'a') countGet += 26;
            if (countGet > 'z') countGet -= 26;
            answer += countGet;
        } else {
            if (countGet < 'A') countGet += 26;
            if (countGet > 'Z') countGet -= 26;
            answer += countGet;
        }
    }
    
    return answer;
}