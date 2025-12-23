#include <algorithm>
#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    if (arr.size() == 0)
        return 0;
    
    int checkOuter = min(static_cast<int>(arr.size()), 100);
    double sumAll = 0;
    for (int i = 0; i < checkOuter; i++) {
        int checkInner = max(-10000, min(arr[i], 10000));
        sumAll += checkInner;
    }
    return sumAll / checkOuter;
}