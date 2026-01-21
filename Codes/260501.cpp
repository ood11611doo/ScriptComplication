#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(long c) {
    if (c == 1)
        return false;
    long sqrted = sqrt(c) + 1;
    for (long i = 2; i < sqrted; i++) {
        if (c % i == 0) {
            return false;
        }
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string newNum;
    while (n >= 1) {
        newNum += to_string(n % k);
        n /= k;
    }
    reverse(newNum.begin(), newNum.end());
    while (newNum.size() > 0) {
        long sized = 0;
        for (int i = 0; i < newNum.size(); i++) {
            if (newNum[i] == '0') {
                newNum = newNum.substr(i + 1, newNum.size() - (i + 1));
                sized /= 10;
                break;
            }
            if (i == newNum.size() - 1) {
                sized += newNum[i] - '0';
                newNum = "";
                break;
            }
            sized += newNum[i] - '0';
            sized *= 10;
        }
        
        if (sized == 0)
            continue;
        
        if (isPrime(sized))
            answer++;
    }
    
    return answer;
}