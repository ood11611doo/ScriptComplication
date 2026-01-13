#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int locY = 0;
    int locX = 0;
    int yMax = park.size() - 1;
    int xMax = park[0].size() - 1;
    for (int i = 0; i < park.size(); i++) {
        for (int j = 0; j < park[i].size(); j++) {
            if (park[i][j] == 'S') {
                locX = j;
                locY = i;
            }
        }
    }
    
    for (const auto& strs : routes) {
        string dirCheck = strs.substr(0, 1);
        int moveCheck = stoi(strs.substr(2, strs.size() - 2));
        
        bool commandSkip = false;
        if (dirCheck == "E") {
            if (locX + moveCheck > xMax) {
                commandSkip = true;
            } else {
                for (int i = 0; i <= moveCheck; i++) {
                    if (park[locY][locX + i] == 'X') {
                        commandSkip = true;
                        break;
                    }
                }
            }
        } else if (dirCheck == "W") {
            if (locX - moveCheck < 0) {
                commandSkip = true;
            } else {
                for (int i = 0; i <= moveCheck; i++) {
                    if (park[locY][locX - i] == 'X') {
                        commandSkip = true;
                        break;
                    }
                }
            }
        } else if (dirCheck == "S") {
            if (locY + moveCheck > yMax) {
                commandSkip = true;
            } else {
                for (int i = 0; i <= moveCheck; i++) {
                    if (park[locY + i][locX] == 'X') {
                        commandSkip = true;
                        break;
                    }
                }
            }
        } else if (dirCheck == "N") {
            if (locY - moveCheck < 0) {
                commandSkip = true;
            } else {
                for (int i = 0; i <= moveCheck; i++) {
                    if (park[locY - i][locX] == 'X') {
                        commandSkip = true;
                        break;
                    }
                }
            }
        }
        
        if (!commandSkip) {
            if (dirCheck == "E") {
                locX += moveCheck;
            } else if (dirCheck == "W") {
                locX -= moveCheck;
            } else if (dirCheck == "S") {
                locY += moveCheck;
            } else if (dirCheck == "N") {
                locY -= moveCheck;
            }
        }
    }
    answer.push_back(locY);
    answer.push_back(locX);
    return answer;
}