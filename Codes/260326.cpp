#include <string>
#include <vector>

using namespace std;

vector<string> orders = { "RT", "CF", "JM", "AN" };

int getScore(int scores, bool reverted) {
    int returnInt = scores - 4;
    return (reverted ? returnInt * -1 : returnInt);
}

string returnTypes(int index) {
    if (index >= orders.size())
        return "";
    return orders[index];
}
int returnIndex(string types) {
    for (int i = 0; i < orders.size(); i++) {
        if (orders[i] == types)
            return i;
    }
    return -1;
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    vector<int> surveys(4, 0);
    for (int i = 0; i < survey.size(); i++) {
        if (survey[i][0] > survey[i][1]) {
            string keys = { survey[i][1], survey[i][0] };
            surveys[returnIndex(keys)] += getScore(choices[i], true);
        } else {
            surveys[returnIndex(survey[i])] += getScore(choices[i], false);
        }
    }
    for (int i = 0; i < surveys.size(); i++) {
        if (surveys[i] > 0)
            answer += returnTypes(i)[1];
        else
            answer += returnTypes(i)[0];
    }
    return answer;
}