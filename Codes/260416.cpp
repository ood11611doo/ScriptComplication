#include <string>
#include <vector>

using namespace std;

bool checkIfBracket(char a, char b) {
    if (a == '(' && b == ')')
        return true;
    if (a == '[' && b == ']')
        return true;
    if (a == '{' && b == '}')
        return true;
    
    return false;
}

bool checkValid(string v) {
    for (int i = 0; i < v.size() - 1; i++) {
        if (checkIfBracket(v[i], v[i + 1])) {
            v.erase(i, 2);
            if (v.size() == 0) {
                break;
            }
            i = -1;
        }
    }
    if (v.size() > 0) return false;
    return true;
}

int solution(string s) {
    int answer = 0;
    for (int i = 0; i < s.size(); i++) {
        s.push_back(s[0]);
        s.erase(0, 1);
        if (checkValid(s)) {
            answer++;
        }
    }
    return answer;
}