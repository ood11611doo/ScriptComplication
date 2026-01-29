#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2);
    int sizeGet = sequence.size();
    int startInd = 0;
    int endInd = 0;
    int sums = sequence[0];
    
    int lengths = sizeGet + 1;

    while (startInd <= endInd && endInd < sizeGet) {
        if (sums == k) {
            int sizeGet = endInd - startInd + 1;
            if (sizeGet < lengths) {
                lengths = sizeGet;
                answer[0] = startInd;
                answer[1] = endInd;
            }
            sums -= sequence[startInd++];
        } else if (sums < k) {
            if (++endInd < sizeGet) sums += sequence[endInd];
        } else {
            sums -= sequence[startInd++];
        }
    }
    return answer;
}