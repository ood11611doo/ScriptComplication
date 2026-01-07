#include <string>
#include <vector>

using namespace std;

int firstAnswer(int index) {
    return (index % 5) + 1;
}
int secondAnswer(int index) {
    if (index % 2 == 0)
        return 2;
    else {
        vector<int> randOrder = { 1, 3, 4, 5 };
        return randOrder[(index / 2) % 4];
    }
}
int thirdAnswer(int index) {
    vector<int> randOrder = { 3, 1, 2, 4 ,5 };
    return randOrder[(index / 2) % 5];
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> ansCount = { 0, 0, 0 };
    for (int i = 0; i < answers.size(); i++) {
        if (firstAnswer(i) == answers[i])
            ansCount[0]++;
        if (secondAnswer(i) == answers[i])
            ansCount[1]++;
        if (thirdAnswer(i) == answers[i])
            ansCount[2]++;
    }
    int largest = 0;
    for (int i = 0; i < ansCount.size(); i++) {
        if (largest < ansCount[i])
            largest = ansCount[i];
    }
    for (int i = 0; i < ansCount.size(); i++) {
        if (largest == ansCount[i])
            answer.push_back(i + 1);
    }
    return answer;
}