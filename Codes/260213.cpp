#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int numConvert = n;
    string revert = "";
    while (numConvert >= 1) {
        revert += to_string(numConvert % 3);
        numConvert /= 3;
    }
    int multiNum = 1;
    for (int i = revert.size() - 1; i >= 0; i--) {
        int checks = revert[i] - '0';
        answer += checks * multiNum;
        multiNum *= 3;
    }
    return answer;
}