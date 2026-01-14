using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;

    do {
        int big = b;
        int small = a;
        if (b < a) {
            big = a;
            small = b;
        }
        
        if (big % 2 == 0 && small + 1 == big) {
            break;
        }
        
        if (a % 2 == 1) a++;
        if (b % 2 == 1) b++;
        a /= 2;
        b /= 2;
        answer++;
    } while (true);

    return answer;
}