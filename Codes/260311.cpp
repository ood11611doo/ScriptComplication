#include <vector>
#include <iostream>
using namespace std;

bool checkNum(int inputs) {
    for (int i = 2; i < inputs - 1; i++) {
        if (inputs % i == 0) return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;

    for (int i = 0; i < nums.size() - 2; i++) {
        for (int j = i + 1; j < nums.size() - 1; j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                int checkThis = nums[i] + nums[j] + nums[k];
                if (checkNum(checkThis))
                    answer++;
            }
        }
    }

    return answer;
}