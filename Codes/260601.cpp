#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    long long limit = static_cast<long long>(d) * d;
    for (long long x = 0; x <= d; x += k) {
        long long max = floor(sqrt(limit - (x * x)));
        answer += (max / k) + 1;
    }
    return answer;
}