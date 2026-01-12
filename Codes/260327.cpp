#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int minX = 50;
    int maxX = 0;
    int minY = 50;
    int maxY = 0;
    for (int i = 0; i < wallpaper.size(); i++) {
        bool exists = false;
        for (int j = 0; j < wallpaper[i].size(); j++) {
            if (wallpaper[i][j] == '#') {
                exists = true;
                if (minX > j) {
                    minX = j;
                }
                if (maxX < j) {
                    maxX = j;
                }
            }
        }
        if (exists) {
            if (minY > i) {
                minY = i;
            }
            if (maxY < i) {
                maxY = i;
            }
        }
    }
    answer.push_back(minY);
    answer.push_back(minX);
    answer.push_back(maxY + 1);
    answer.push_back(maxX + 1);
    return answer;
}