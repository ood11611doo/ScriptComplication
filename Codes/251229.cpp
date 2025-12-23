#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    int check1 = max(-50000, min(num1, 50000));
    int check2 = max(-50000, min(num2, 50000));
    return check1 + check2;
}