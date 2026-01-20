#include <string>
#include <vector>

using namespace std;

int maxCheck = 0;
vector<bool> checkVisit;

void findVal(int check, int k, vector<vector<int>> dungeons) {
    maxCheck = max(maxCheck, check);
    
    for (int i = 0; i < dungeons.size(); i++) {
        if (!checkVisit[i] && k >= dungeons[i][0]) {
            checkVisit[i] = true;
            findVal(check + 1, k - dungeons[i][1], dungeons);
            checkVisit[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    for (int i = 0; i < dungeons.size(); i++) {
        checkVisit.push_back(false);
    }
    findVal(0, k, dungeons);
    return maxCheck;
}