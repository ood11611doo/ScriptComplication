#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool sorter(int first, int second) {
    string fCheck = to_string(first);
    string sCheck = to_string(second);
    return fCheck + sCheck > sCheck + fCheck;
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), sorter);
    if (numbers[0] == 0) {
        return "0";
    }
    for (int i = 0; i < numbers.size(); i++) {
        answer += to_string(numbers[i]);
    }
    return answer;
}