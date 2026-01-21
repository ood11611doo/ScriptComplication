#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int timesGet(string timeStr) {
    int hours = stoi(timeStr.substr(0, 2));
    int minutes = stoi(timeStr.substr(3, 2));
    
    return (hours * 60) + minutes;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map <string, int> inRec;
    map <string, int> totalTime;
    for (int i = 0; i < records.size(); i++) {
        string times = records[i].substr(0, 5);
        string nums = records[i].substr(6, 4);
        string getCheck = records[i].substr(11, records[i].size() - 11);
        
        if (getCheck == "IN") {
            inRec[nums] = timesGet(times);
        } else if (getCheck == "OUT") {
            int outTime = timesGet(times);
            totalTime[nums] += outTime - inRec[nums];
            auto it = inRec.find(nums);
            inRec.erase(it);
        }
    }
    
    for (const auto& vals : inRec) {
        int lastTime = timesGet("23:59");
        totalTime[vals.first] += lastTime - vals.second;
    }
    
    for (const auto& vals : totalTime) {
        if (vals.second <= fees[0]) {
            answer.push_back(fees[1]);
            continue;
        }
        
        int timeCheck = ceil((vals.second - fees[0]) / static_cast<float>(fees[2]));
        answer.push_back(fees[1] + (timeCheck * fees[3]));
    }
    return answer;
}