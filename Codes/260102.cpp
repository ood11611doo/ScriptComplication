#include <algorithm>
#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    if (numbers.size() == 0)
        return 0;
    
    int checkOuter = min(static_cast<int>(numbers.size()), 100);
    double allSum = 0;
    for (int i = 0; i < checkOuter; i++) {
        allSum += numbers[i];
    }
    
    return allSum / checkOuter;
}