#include <string>
#include <vector>

using namespace std;

int getCount(int index) {
    int returnCount = 0;
    for (int i = 1; i <= index; i++) {
        if (index % i == 0)
            returnCount++;
    }
    return returnCount;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    for (int i = 1; i <= number; i++) {
        int getNum = getCount(i);
        if (getNum > limit)
            answer += power;
        else
            answer += getNum;
    }
    return answer;
}