#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <vector>

using namespace std;

int checkNum(int num) {
    if (num <= 1) {
        return true;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return true;
        }
    }
    return false;
}

int solution(string numbers) {
    int answer = 0;
    set<int> allNums;
    
    sort(numbers.begin(), numbers.end());
    do {
        for (int i = 1; i <= numbers.length(); i++) {
            string check = numbers.substr(0, i);
            int adds = stoi(check);
            allNums.insert(adds);
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    for (const auto& checker : allNums) {
        if (!checkNum(checker)) {
            answer++;
        }
    }
    
    return answer;
}