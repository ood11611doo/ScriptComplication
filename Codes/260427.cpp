#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    bool added = false;
    while (progresses.size() > 0) {
        if (progresses[0] >= 100) {
            if (!added) {
                answer.push_back(1);
            } else {
                answer[answer.size() - 1]++;
            }
            
            added = true;
            
            progresses.erase(progresses.begin());
            speeds.erase(speeds.begin());
            
            continue;
        }
        
        added = false;
        for (int i = 0; i < progresses.size(); i++) {
            progresses[i] += speeds[i];
        }
    }
    return answer;
}