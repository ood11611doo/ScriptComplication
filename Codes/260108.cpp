#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> allNum;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            allNum.push_back(i);
        }
    }
    for (const int& vals : allNum) {
        answer += vals;
    }
    return answer;
}