#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    int min = a >= b ? b : a;
    int max = a >= b ? a : b;
    for (int i = min; i <= max; i++)
        answer += i;
    return answer;
}