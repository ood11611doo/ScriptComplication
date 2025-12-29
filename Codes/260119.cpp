#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int originNum = x;
    int numComp = 0;
    while (originNum >= 1) {
        numComp += originNum % 10;
        originNum /= 10;
    }
    if (x % numComp != 0)
        answer = false;
    return answer;
}