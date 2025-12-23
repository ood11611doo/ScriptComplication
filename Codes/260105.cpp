#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    if (num == 0)
        return "Even";
    
    if (abs(num) % 2 == 1)
        return "Odd";
    else
        return "Even";
}