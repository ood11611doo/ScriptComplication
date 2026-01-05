#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for (int i = 0; i < numbers.size() - 1; i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            int sumCheck = numbers[i] + numbers[j];
            if (find(answer.begin(), answer.end(), sumCheck) == answer.end()) {
                answer.push_back(sumCheck);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}