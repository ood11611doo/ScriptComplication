#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    if (n <= 2) {
        return n;
    }
    long prevNum = 1;
    long curNum = 2;
    while (n > 2) {
        n--;
        long numRec = curNum;
        curNum = (prevNum + numRec) % 1234567;
        prevNum = numRec;
    }
    return curNum;
}