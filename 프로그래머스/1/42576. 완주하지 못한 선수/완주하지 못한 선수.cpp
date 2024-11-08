#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> um;
    for(auto e : participant)
    {
        um[e]++;
    }
    for(auto e : completion)
    {
        um[e]--;
    }
    for(auto e : um)
    {
        if(e.second) return e.first;
    }
}