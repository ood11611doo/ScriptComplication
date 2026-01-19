#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> wtCount;
    for (int i = 0; i < want.size(); i++) {
        wtCount[want[i]] = number[i];
    }
    
    int matchChecks = 0;
    for (int i = 0; i < discount.size(); i++) {
        if (wtCount.count(discount[i]) > 0) {
            matchChecks++;
            wtCount[discount[i]]--;
        } else {
            matchChecks = 0;
        }
        
        if (i >= 10) {
            if (wtCount.count(discount[i - 10]) > 0) {
                wtCount[discount[i - 10]]++;
            }
        }
        
        if (matchChecks >= 10) {
            bool allMatched = true;
            for (const auto& vals : wtCount) {
                if (vals.second > 0)
                    allMatched = false;
            }
            if (allMatched) {
                answer++;
            }
        }
    }
    return answer;
}