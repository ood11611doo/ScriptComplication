#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    map<string, int> categories;
    for (int i = 0; i < clothes.size(); i++) {
        categories[clothes[i][1]]++;
    }
    
    for (const auto& its : categories) {
        if (answer == 0) {
            answer = its.second + 1;
            continue;
        }
        
        answer *= its.second + 1;
    }
    answer--;
    return answer;
}