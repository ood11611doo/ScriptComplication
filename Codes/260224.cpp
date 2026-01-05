#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int outerUsed;
bool funcSort(string a, string b) {
    if (a[outerUsed] == b[outerUsed])
        return a < b;
    return a[outerUsed] < b[outerUsed];
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer = strings;
    outerUsed = n;
    sort(answer.begin(), answer.end(), funcSort);
    return answer;
}