#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (const auto& inners : commands) {
        vector<int> newSort(array.begin() + inners[0] - 1, array.begin() + inners[1]);
        sort(newSort.begin(), newSort.end());
        answer.push_back(newSort[inners[2] - 1]);
    }
    return answer;
}