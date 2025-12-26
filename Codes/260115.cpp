#include <cmath>
#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    float getSqrt = sqrt(n);
    if (getSqrt != floor(getSqrt))
        return -1;
    answer = pow((getSqrt + 1), 2);
    return answer;
}