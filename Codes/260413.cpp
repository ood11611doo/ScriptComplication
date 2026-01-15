#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    bool breakCheck = false;
    while (!breakCheck) {
        breakCheck = true;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > answer) {
                breakCheck = false;
                break;
            }
            if (answer % arr[i] != 0) {
                breakCheck = false;
                break;
            }
        }
        
        if (!breakCheck) answer++;
    }
    return answer;
}