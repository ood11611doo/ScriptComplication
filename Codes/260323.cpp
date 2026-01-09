#include <string>
#include <map>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char, int> clickPair;
    for (const auto& keypad : keymap) {
        for (int i = 0; i < keypad.size(); i++) {
            auto it = clickPair.find(keypad[i]);
            if (it == clickPair.end()) {
                clickPair[keypad[i]] = i + 1;
            } else if (clickPair[keypad[i]] > i + 1) {
                clickPair[keypad[i]] = i + 1;
            }
        }
    }
    for (const auto& wordWrite : targets) {
        int totalClick = 0;
        for (int i = 0; i < wordWrite.size(); i++) {
            if (clickPair[wordWrite[i]] == 0) {
                totalClick = -1;
                break;
            }
            
            totalClick += clickPair[wordWrite[i]];
        }
        answer.push_back(totalClick);
    }
    return answer;
}