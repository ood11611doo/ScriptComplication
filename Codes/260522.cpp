#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    long long sum1 = 0;
    long long sum2 = 0;
    for (const int& inners : queue1) {
        sum1 += inners;
    }
    for (const int& inners : queue2) {
        sum2 += inners;
    }
    long long sumTotal = sum1 + sum2;
    if (sumTotal % 2 != 0) {
        return answer;
    }
    long long checkThis = sumTotal / 2;
    
    answer = 0;
    int c1 = 0;
    int c2 = 0;
    int maxCheck = queue1.size() * 4;

    while (answer < maxCheck) {
        if (sum1 == checkThis) {
            break;
        }
        
        if (sum1 > checkThis) {
            int val = queue1[c1];
            sum1 -= val;
            sum2 += val;
            queue2.push_back(val);
            c1++;
        } else {
            int val = queue2[c2];
            sum2 -= val;
            sum1 += val;
            queue1.push_back(val);
            c2++;
        }
        answer++;
    }
    if (answer == maxCheck) {
        answer = -1;
    }
    return answer;
}