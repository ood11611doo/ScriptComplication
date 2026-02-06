#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;

    vector<vector<pair<int, int>>> lengths(N + 1);
    for (const auto& i : road) {
        int v1 = i[0];
        int v2 = i[1];
        int le = i[2];
        lengths[v1].push_back({v2, le});
        lengths[v2].push_back({v1, le});
    }
    
    vector<int> dists(N + 1, 10000000);
    dists[1] = 0;
    
    priority_queue<pair<int ,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    
    while (pq.size() > 0) {
        int curD = pq.top().first;
        int curR = pq.top().second;
        pq.pop();
        
        if (curD > dists[curR]) {
            continue;
        }
        
        for (const auto& ed : lengths[curR]) {
            int nextR = ed.first;
            int nextD = curD + ed.second;
            
            if (nextD < dists[nextR]) {
                dists[nextR] = nextD;
                pq.push({nextD, nextR});
            }
        }
    }
    
    for (int i = 1; i <= N; i++) {
        if (dists[i] <= K) {
            answer++;
        }
    }

    return answer;
}