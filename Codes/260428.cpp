#include <string>
#include <vector>

using namespace std;

int returnHighest(vector<int> queue) {
    int highest = 0;
    for (int i = 0; i < queue.size(); i++) {
        if (queue[i] > highest) {
            highest = queue[i];
        }
    }
    return highest;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    while (true) {
        int high = returnHighest(priorities);
        if (priorities[0] < high) {
            int priorRec = priorities[0];
            priorities.erase(priorities.begin());
            priorities.push_back(priorRec);
        } else {
            answer++;
            if (location == 0) {
                return answer;
            }
            priorities.erase(priorities.begin());
        }
        
        location--;
        if (location < 0) {
            location = priorities.size() - 1;
        }
    }
    return answer;
}