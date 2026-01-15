#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> counts;
    for (int i = 0; i < tangerine.size(); i++) {
        counts[tangerine[i]]++;
    }
    vector<int> countCheck;
    for (const auto& inners : counts) {
        countCheck.push_back(inners.second);
    }
    sort(countCheck.begin(), countCheck.end(), [](const int& a, const int& b) {
        return a > b;
    });
    for (int i = 0; i < countCheck.size(); i++) {
        k -= countCheck[i];
        if (k <= 0) {
            answer = i + 1;
            break;
        }
    }
    
    return answer;
}