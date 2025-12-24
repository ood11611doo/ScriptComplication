#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    int numGet = n;
    while (numGet >= 1) {
        answer += numGet % 10;
        numGet /= 10;
    }

    return answer;
}