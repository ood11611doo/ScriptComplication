#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int leftCount = n;
    while (leftCount >= a) {
        int leftGet = leftCount % a;
        int getCount = (leftCount / a) * b;
        answer += getCount;
        leftCount = getCount + leftGet;
    }
    return answer;
}