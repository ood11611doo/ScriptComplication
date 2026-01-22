#include <string>
#include <vector>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    vector<int> first(10000, 0);
    int firstType = 0;
    vector<int> second(10000, 0);
    int secondType = 0;
    for (int i = 0; i < topping.size(); i++) {
        if (second[topping[i] - 1] == 0) {
            secondType++;
        }
        second[topping[i] - 1]++;
    }
    for (int i = 0; i < topping.size(); i++) {
        if (first[topping[i] - 1] == 0) {
            firstType++;
        }
        first[topping[i] - 1]++;
        
        second[topping[i] - 1]--;
        if (second[topping[i] - 1] == 0) {
            secondType--;
        }
        
        if (firstType == secondType) {
            answer++;
        }
    }
    return answer;
}