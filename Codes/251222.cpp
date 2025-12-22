#include <algorithm>

using namespace std;

int solution(int num1, int num2) {
    int answer = 0;
    int minVal = -50000;
    int maxVal = 50000;
    answer = max(minVal, min(num1, maxVal)) - max(minVal, min(num2, maxVal));
    return answer;
}