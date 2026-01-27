#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> saves;
    int boxNow = 1;
    int index = 0;
    
    while (boxNow <= order.size()) {
        saves.push(boxNow);
        while (!saves.empty() && saves.top() == order[index]) {
            saves.pop();
            index++;
            answer++;
        }
        boxNow++;
    }
    
    return answer;
}