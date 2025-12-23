#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int sums = 0;
    int check = max(1, min(n, 1000));
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1)
            continue;
        sums += i;
    }
    return sums;
}