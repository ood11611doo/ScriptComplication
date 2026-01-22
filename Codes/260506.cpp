#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    stack<int> inds;
    for (int i = 0; i < numbers.size(); i++) {
        while (inds.size() > 0 && numbers[inds.top()] < numbers[i]) {
            answer[inds.top()] = numbers[i];
            inds.pop();
        }
        inds.push(i);
    }
    return answer;
}