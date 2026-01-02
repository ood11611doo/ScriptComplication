#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int xSize = 0;
    int ySize = 0;
    for (int i = 0; i < sizes.size(); i++) {
        sort(sizes[i].begin(), sizes[i].end());
        if (sizes[i][0] > xSize)
            xSize = sizes[i][0];
        if (sizes[i][1] > ySize)
            ySize = sizes[i][1];
    }
    answer = xSize * ySize;
    return answer;
}