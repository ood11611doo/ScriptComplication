#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    map<int, bool> allAnswer;
    for (int i = 0; i < elements.size(); i++) {
        for (int j = 0; j < elements.size(); j++) {
            int allAddNum = 0;
            for (int k = 0; k < j + 1; k++) {
                int addInd = i + j + k;
                while (addInd >= elements.size()) {
                    addInd -= elements.size();
                }
                allAddNum += elements[addInd];
            }
            allAnswer[allAddNum] = false;
        }
    }
    return allAnswer.size();
}