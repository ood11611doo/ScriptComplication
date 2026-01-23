#include <string>
#include <vector>

using namespace std;

long long toBitRev(long long nums) {
    if (nums % 2 == 0) {
        return nums + 1;
    }
    
    long long adds = 1;
    while (true) {
        if ((adds & nums) == false) {
            break;
        }
        adds = adds << 1;
    }
    
    long long ans = (nums | adds) & ~(adds >> 1);
    return ans;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (int i = 0; i < numbers.size(); i++) {
        answer.push_back(toBitRev(numbers[i]));
    }
    return answer;
}