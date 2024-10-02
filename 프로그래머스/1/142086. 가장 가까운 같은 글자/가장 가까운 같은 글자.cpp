#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<char, int> table;
    
    for(auto e : s)
    {
        if(table[e] == 0) answer.push_back(-1);
        else answer.push_back(table[e]);
        if(table[e]) table[e] = 0;
        for(auto f : table)
        {
            table[f.first]++;
        }
    }
    return answer;
}