#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    vector<string> check1(cards1);
    vector<string> check2(cards2);
    for (int i = 0; i < goal.size(); i++) {
        if (check1.size() > 0 && goal[i] == check1[0]) {
            check1.erase(check1.begin());
            continue;
        }
        if (check2.size() > 0 && goal[i] == check2[0]) {
            check2.erase(check2.begin());
            continue;
        }
        
        answer = "No";
        break;
    }
    return answer;
}