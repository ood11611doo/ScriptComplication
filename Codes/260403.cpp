#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> intGets;
    while (s.size() > 0) {
        size_t inds = s.find(' ');
        if (inds == string::npos) {
            int conv = stoi(s);
            s = "";
            intGets.push_back(conv);
        } else {
            int conv = stoi(s.substr(0, inds));
            s = s.substr(inds + 1, s.size() - (inds + 1));
            intGets.push_back(conv);
        }
    }
    sort(intGets.begin(), intGets.end());
    answer += to_string(intGets[0]);
    answer += " ";
    answer += to_string(intGets[intGets.size() - 1]);
    return answer;
}