#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    unordered_map<char, int> um;
    for(auto e : X)
    {
        um[e]++;
    }
    for(auto e : Y)
    {
        if(um[e])
        {
            um[e]--;
            answer += e;
        }
    }
    if(answer.empty()) return "-1";
    sort(answer.begin(), answer.end(), greater<int>());
    if(answer[0] == '0') return "0";
    return answer;
}