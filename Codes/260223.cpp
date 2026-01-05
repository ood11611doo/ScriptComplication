#include <string>
#include <vector>
#include <regex>

using namespace std;

int solution(string s) {
    int answer = 0;
    string origin = s;
    vector<string> repList = {"zero", "one", "two", "three", "four",
                              "five" , "six", "seven", "eight", "nine"};
    for (int i = 0; i < repList.size(); i++) {
        origin = regex_replace(origin, regex(repList[i]), to_string(i));
    }
    answer = stoi(origin);
    return answer;
}