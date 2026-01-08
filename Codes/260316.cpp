#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int minCor = win_nums.size();
    int freeNum = 0;
    for (int i = 0; i < lottos.size(); i++) {
        if (lottos[i] == 0) {
            freeNum++;
            continue;
        }
        
        auto it = find(win_nums.begin(), win_nums.end(), lottos[i]);
        if (it != win_nums.end()) {
            minCor--;
        }
    }
    if (minCor < 6) {
        minCor++;
    }
    int maxCor = minCor - freeNum;
    if (maxCor < 1) {
        maxCor = 1;
    }
    answer.push_back(maxCor);
    answer.push_back(minCor);
    return answer;
}