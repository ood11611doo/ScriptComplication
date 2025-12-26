#include <algorithm>
#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long copied = n;
    vector<int> sorts;
    while (copied >= 1) {
        sorts.push_back(copied % 10);
        copied /= 10;
    }
    sort(sorts.begin(), sorts.end());
    reverse(sorts.begin(), sorts.end());
    for (const int& vals : sorts) {
        answer += vals;
        answer *= 10;
    }
    answer /= 10;
    return answer;
}