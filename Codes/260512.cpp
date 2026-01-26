#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> bridges;
    int curWeight = 0;
    int curIndex = 0;
    
    for (int i = 0; i < bridge_length; i++) {
        bridges.push(0);
    }
    while (bridges.size() > 0) {
        answer++;
        curWeight -= bridges.front();
        bridges.pop();
        
        if (curIndex < truck_weights.size()) {
            if (weight >= curWeight + truck_weights[curIndex]) {
                bridges.push(truck_weights[curIndex]);
                curWeight += truck_weights[curIndex];
                curIndex++;
            } else {
                bridges.push(0);
            }
        }
    }
    return answer;
}