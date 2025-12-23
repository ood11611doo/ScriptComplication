#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    int check1 = max(0, min(num1, 10000));
    int check2 = max(0, min(num2, 10000));
    if (check1 == check2)
        return 1;
    else
        return -1;
}