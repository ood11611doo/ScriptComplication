#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    for (int i = 0; i < lost.size(); i++) {
        auto it = find(reserve.begin(), reserve.end(), lost[i]);
        if (it != reserve.end()) {
            reserve.erase(it);
            lost[i] = 0;
        }
    }
    
    for (int i = 0; i < lost.size(); i++) {
        if (lost[i] == 0)
            continue;
        
        auto it = find(reserve.begin(), reserve.end(), lost[i] - 1);
        if (it != reserve.end()) {
            reserve.erase(it);
            lost[i] = 0;
            continue;
        }
        it = find(reserve.begin(), reserve.end(), lost[i] + 1);
        if (it != reserve.end()) {
            reserve.erase(it);
            lost[i] = 0;
            continue;
        }
    }
    
    for (int i = 0; i < lost.size(); i++) {
        if (lost[i] == 0)
            answer++;
    }
    
    return answer;
}