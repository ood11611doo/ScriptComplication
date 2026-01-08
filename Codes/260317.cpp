#include <string>
#include <vector>

using namespace std;

bool checkPron(string babble) {
    vector<string> enabled = { "aya", "ye", "woo", "ma" };
    string prevPron = "";
    
    bool decCheck = false;
    while (!decCheck) {
        decCheck = true;
        for (int i = 0; i < enabled.size(); i++) {
            if (babble.size() < enabled[i].size()) {
                continue;
            }
            
            string subCheck = babble.substr(0, enabled[i].size());
            if (subCheck != prevPron && subCheck == enabled[i]) {
                prevPron = subCheck;
                babble.erase(0, enabled[i].size());
                decCheck = false;
                break;
            }
        }
    }
    
    if (babble.size() == 0)
        return true;
    else
        return false;
}

int solution(vector<string> babbling) {
    int answer = 0;
    for (int i = 0; i < babbling.size(); i++) {
        if (checkPron(babbling[i])) {
            answer++;
        }
    }
    return answer;
}