#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    long long nVal = n;
    while (nVal >= 1) {
        int single = nVal % 10;
        answer.push_back(single);
        nVal /= 10;
    }
    return answer;
}