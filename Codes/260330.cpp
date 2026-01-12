#include <string>
#include <vector>
#include <map>

using namespace std;

int toAbsoluteLength(string dates) {
    vector<int> splitter;
    while (dates.size() > 0) {
        for (int i = 0; i < dates.size(); i++) {
            if (dates[i] == '.') {
                int getStr = stoi(dates.substr(0, i));
                splitter.push_back(getStr);
                dates = dates.substr(i + 1, dates.size() - (i + 1));
                break;
            }
            if (i == dates.size() - 1) {
                int getStr = stoi(dates);
                splitter.push_back(getStr);
                dates = "";
                break;
            }
        }
    }
    if (splitter.size() != 3)
        return -1;
    
    int returnCount = 0;
    returnCount += splitter[0] * (12 * 28);
    returnCount += splitter[1] * 28;
    returnCount += splitter[2];
    
    return returnCount;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    int todayAbs = toAbsoluteLength(today);
    map<string, int> addCount;
    for (int i = 0; i < terms.size(); i++) {
        string getName = terms[i].substr(0, 1);
        int getLength = stoi(terms[i].substr(2, terms[i].size() - 2)) * 28;
        addCount[getName] = getLength;
    }
    
    for (int i = 0; i < privacies.size(); i++) {
        string splitDates = privacies[i].substr(0, 10);
        string getName = privacies[i].substr(11, 1);
        int realDate = toAbsoluteLength(splitDates) + addCount[getName];
        if (realDate <= todayAbs)
            answer.push_back(i + 1);
    }
    return answer;
}