#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

char arrs[] = {'A', 'E', 'I', 'O', 'U'};
map<char, int> pairs = {
    {'A', 0},
    {'E', 1},
    {'I', 2},
    {'O', 3},
    {'U', 4}
};

int solution(string word) {
    int answer = 0;
    vector<string> lists;
    string lastWord = "A";
    while (true) {
        lists.push_back(lastWord);
        if (lastWord == "UUUUU") {
            break;
        }
        
        if (lastWord.size() < 5) {
            lastWord += arrs[0];
        } else if (pairs[lastWord[4]] < 4) {
            lastWord[4] = arrs[pairs[lastWord[4]] + 1];
        } else {
            lastWord.erase(4, 1);
            for (int i = lastWord.size() - 1; i >= 0; i--) {
                if (pairs[lastWord[i]] < 4) {
                    lastWord[i] = arrs[pairs[lastWord[i]] + 1];
                    break;
                } else {
                    lastWord.erase(i, 1);
                }
            }
        }
    }
    
    for (int i = 0; i < lists.size(); i++) {
        if (word == lists[i]) {
            answer = i + 1;
            break;
        }
    }
    
    return answer;
}