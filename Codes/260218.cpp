#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    long checkNum = stol(p);
    for (int i = 0; i < t.size() - (p.size() - 1); i++) {
        long newNum = stol(t.substr(i, p.size()));
        if (newNum <= checkNum)
            answer++;
    }
    return answer;
}