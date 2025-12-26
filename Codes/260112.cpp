#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    for (int i = 0; i < n; i++) {
        long iNum = (i + 1) * x;
        answer.push_back(iNum);
    }
    return answer;
}