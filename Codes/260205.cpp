#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string s) {
    string answer = "";
    map<int, int, greater<int>> keys;
    for (int i = 0; i < s.size(); i++) {
        keys[(int)s[i]]++;
    }
    for (const auto& [keysIn, valsIn] : keys) {
        for (int i = 0; i < valsIn; i++) {
            answer += (char)keysIn;
        }
    }
    return answer;
}