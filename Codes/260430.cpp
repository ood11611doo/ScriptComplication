#include <string>
#include <vector>

using namespace std;

vector<int> nums;
int targets;

void repeator(int& ansCount, int index, int checkNum) {
    if (index == nums.size()) {
        if (checkNum == targets) {
            ansCount++;
        }
        return;
    }
    
    repeator(ansCount, index + 1, checkNum + nums[index]);
    repeator(ansCount, index + 1, checkNum - nums[index]);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    nums = numbers;
    targets = target;
    repeator(answer, 0, 0);
    return answer;
}