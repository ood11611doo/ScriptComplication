#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, vector<int>> repCheck;
    for (int i = 0; i < id_list.size(); i++) {
        answer.push_back(0);
    }
    
    for (int i = 0; i < report.size(); i++) {
        size_t it = report[i].find(' ');
        string user = report[i].substr(0, it);
        string rep = report[i].substr(it + 1, report[i].size() - (it + 1));
        
        int userInd = find(id_list.begin(), id_list.end(), user) - id_list.begin();
        
        auto inCheck = find(repCheck[rep].begin(), repCheck[rep].end(), userInd);
        if (inCheck == repCheck[rep].end()) {
            repCheck[rep].push_back(userInd);
        }
    }
    
    for (const auto& vals : repCheck) {
        if (vals.second.size() >= k) {
            for (const auto& inns : vals.second) {
                answer[inns]++;
            }
        }
    }
    
    return answer;
}