#include <string>
#include <vector>

using namespace std;

int dayOfMonth(int year, int month) {
    static const int daysInMonth[] = 
        { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2) {
        if (year % 400 == 0)
            return 29;
        else if (year % 100 == 0)
            return 28;
        else if (year % 4 == 0)
            return 29;
        return 28;
    }
    return daysInMonth[month];
}

string solution(int a, int b) {
    string answer = "";
    int leftCount = -1;
    for (int i = 1; i < a; i++) {
        int maxDay = dayOfMonth(2016, i);
        leftCount += maxDay % 7;
    }
    
    leftCount += b % 7;
    while (leftCount >= 7)
        leftCount -= 7;
    
    switch (leftCount) {
        case 0:
            answer = "FRI";
            break;
        case 1:
            answer = "SAT";
            break;
        case 2:
            answer = "SUN";
            break;
        case 3:
            answer = "MON";
            break;
        case 4:
            answer = "TUE";
            break;
        case 5:
            answer = "WED";
            break;
        case 6:
            answer = "THU";
            break;
    }
    
    return answer;
}