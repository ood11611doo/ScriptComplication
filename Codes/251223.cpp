#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    int answer = max(0, min(num1, 100)) * max(0, min(num2, 100));
    return answer;
}