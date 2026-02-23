#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

bool calcs(int startX, int startY, vector<string>& parts) {
    queue<pair<pair<int, int>, int>> q;
    bool checked[5][5] = { false, };

    q.push({ {startX, startY}, 0 });
    checked[startX][startY] = true;

    while (q.size() > 0) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        q.pop();

        if (d > 0 && d <= 2 && parts[x][y] == 'P') return false;
        if (d >= 2) continue;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
                if (!checked[nx][ny] && parts[nx][ny] != 'X') {
                    checked[nx][ny] = true;
                    q.push({ {nx, ny}, d + 1 });
                }
            }
        }
    }
    return true;
}
int checks(vector<string> parts) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (parts[i][j] == 'P') {
                if (!calcs(i, j, parts)) return 0;
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (int i = 0; i < places.size(); i++) {
        answer.push_back(checks(places[i]));
    }
    return answer;
}