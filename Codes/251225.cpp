#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(int age) {
    int answer = 0;
    int ageInput = max(1, min(age, 120)) - 1;
    answer = 2022 - ageInput;
    return answer;
}