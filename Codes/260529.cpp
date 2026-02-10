#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int timeConversion(string time) {
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));
    return (hour * 60) + minute;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    sort(book_time.begin(), book_time.end());
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for (const auto& book : book_time) {
        int start = timeConversion(book[0]);
        int end = timeConversion(book[1]) + 10;
        
        if (pq.size() > 0 && pq.top() <= start) {
            pq.pop();
        }
        pq.push(end);
    }
    answer = pq.size();
    return answer;
}