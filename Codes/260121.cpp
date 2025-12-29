#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long inputNum = num;
    while (inputNum != 1 && answer < 500) {
        if (inputNum % 2 == 0)
            inputNum /= 2;
        else
            inputNum = (inputNum * 3) + 1;
        
        answer++;
    }
    if (answer >= 500)
        return -1;
    return answer;
}