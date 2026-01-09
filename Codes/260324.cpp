#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    for (const auto& ch : s) {
        char inputs = ch;
        for (int i = 0; i < index; i++) {
            inputs = inputs + 1;
            if (inputs > 'z')
                inputs = 'a';
            auto it = find(skip.begin(), skip.end(), inputs);
            if (it != skip.end()) {
                i--;
            }
        }
        answer += inputs;
    }
    return answer;
}