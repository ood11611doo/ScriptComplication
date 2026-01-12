#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> reorders;
    for (int i = 0; i < players.size(); i++) {
        reorders[players[i]] = i;
    }
    for (int i = 0; i < callings.size(); i++) {
        int indCur = reorders[callings[i]];
        int indFor = indCur - 1;
        
        string saveFor = players[indFor];
        players[indFor] = callings[i];
        players[indCur] = saveFor;
        reorders[callings[i]] = indFor;
        reorders[saveFor] = indCur;
    }
    return players;
}