#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int nodeCounter(int startNode, int n, const vector<vector<int>>& wCheck) {
    vector<bool> visited(n + 1, false);
    queue<int> q;
    
    q.push(startNode);
    visited[startNode] = true;
    int count = 1;
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        for (int neighbor : wCheck[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
                count++;
            }
        }
    }
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;

    for (int i = 0; i < wires.size(); i++) {
        vector<vector<int>> adj(n + 1);
        for (int j = 0; j < wires.size(); j++) {
            if (i == j) continue;
            
            int u = wires[j][0];
            int v = wires[j][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int count1 = nodeCounter(wires[i][0], n, adj);
        int count2 = n - count1;
        
        answer = min(answer, abs(count1 - count2));
    }
    
    return answer;
}