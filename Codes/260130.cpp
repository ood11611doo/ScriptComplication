#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int lengthGet = s.size();
    int midGet = lengthGet / 2;
    if (lengthGet % 2 == 0)
        answer += s[midGet - 1];
    answer += s[midGet];
    return answer;
}