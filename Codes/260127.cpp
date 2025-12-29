#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    int sizeGet = phone_number.size();
    for (int i = 0; i < sizeGet; i++) {
        if (i < sizeGet - 4)
            answer += "*";
        else
            answer += phone_number[i];
    }
    return answer;
}