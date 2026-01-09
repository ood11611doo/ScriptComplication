#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    string ingStr = "";
    string burStr = "1231";
    for (int i = 0; i < ingredient.size(); i++) {
        ingStr += to_string(ingredient[i]);
        if (ingStr.size() >= burStr.size()) {
            int subGet = ingStr.size() - burStr.size();
            string checkIn = ingStr.substr(subGet, burStr.size());
            if (checkIn == burStr) {
                answer++;
                ingStr.pop_back();
                ingStr.pop_back();
                ingStr.pop_back();
                ingStr.pop_back();
            }
        }
    }
    return answer;
}