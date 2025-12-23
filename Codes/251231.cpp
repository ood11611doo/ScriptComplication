#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(int angle) {
    int check = max(1, min(angle, 180));
    if (angle < 90)
        return 1;
    else if (angle == 90)
        return 2;
    else if (angle < 180)
        return 3;
    else
        return 4;
}