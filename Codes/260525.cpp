#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(int startX, int startY, vector<string>& maps, vector<vector<bool>>& visited) {
    int rows = maps.size();
    int cols = maps[0].size();
    int foodFound = 0;
    
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        foodFound += maps[x][y] - '0';
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                if (maps[nx][ny] != 'X' && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
    
    return foodFound;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int rows = maps.size();
    int cols = maps[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (maps[i][j] != 'X' && !visited[i][j]) {
                answer.push_back(bfs(i, j, maps, visited));
            }
        }
    }
    
    if (answer.empty()) {
        return {-1};
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}