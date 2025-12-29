#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for (const auto& inner : arr) {
        if (inner % divisor == 0)
            answer.push_back(inner);
    }
    sort(answer.begin(), answer.end());
    if (answer.size() == 0)
        answer.push_back(-1);
    return answer;
}