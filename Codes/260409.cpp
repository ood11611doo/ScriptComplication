#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int width = 0;
    int height = 0;
    int blockSize = brown + yellow;
    
    for (int i = 3; i <= sqrt(blockSize); i++) {
        if (blockSize % i == 0) {
            int widthCheck = blockSize / i;
            if ((widthCheck - 2) * (i - 2) == yellow) {
                width = widthCheck;
                height = i;
            }
        }
    }
    
    answer.push_back(width);
    answer.push_back(height);
    
    return answer;
}