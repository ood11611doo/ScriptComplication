#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool funcSort(int a, int b) {
    return a > b;
}

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> leaderboard;
    for (int i = 0; i < score.size(); i++) {
        if (leaderboard.size() < k) {
            leaderboard.push_back(score[i]);
            sort(leaderboard.begin(), leaderboard.end(), funcSort);
            answer.push_back(leaderboard[leaderboard.size() - 1]);
            continue;
        }
        
        if (score[i] > leaderboard[k - 1]) {
            leaderboard.pop_back();
            leaderboard.push_back(score[i]);
            sort(leaderboard.begin(), leaderboard.end(), funcSort);
        }
        
        answer.push_back(leaderboard[k - 1]);
    }
    return answer;
}