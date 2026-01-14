#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    long prevNum = 0;
    long curNum = 1;
    while (n > 1) {
        n--;
        long numRec = curNum;
        curNum = (prevNum + numRec) % 1234567;
        prevNum = numRec;
    }
    answer = curNum;
    return answer;
}