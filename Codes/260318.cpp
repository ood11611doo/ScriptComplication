#include <cmath>
#include <string>
#include <vector>

using namespace std;

bool newSorter(int a, int b) {
    return a > b;
}

string solution(string X, string Y) {
    string answer = "";
    vector<int> numX(10, 0);
    vector<int> numY(10, 0);
    for (int i = 0; i < X.size(); i++) {
        int checkInt = X[i] - '0';
        numX[checkInt]++;
    }
    for (int i = 0; i < Y.size(); i++) {
        int checkInt = Y[i] - '0';
        numY[checkInt]++;
    }
    bool zeroOther = false;
    for (int i = numX.size() - 1; i >= 0; i--) {
        int countMin = min(numX[i], numY[i]);
        if (i > 0 && countMin > 0) {
            zeroOther = true;
        }
        while (countMin > 0) {
            answer += to_string(i);
            countMin--;
        }
    }
    
    if (answer == "")
        return "-1";
    else if (!zeroOther)
        return "0";
    else
        return answer;
    
}