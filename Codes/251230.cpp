#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    float check1 = max(1, min(num1, 100));
    float check2 = max(1, min(num2, 100));
    return (check1 / check2) * 1000;
}