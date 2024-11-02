#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer(2,7);
    
    unordered_map<int, int> um;
    for(int i{}; i < win_nums.size(); i++)
    {
        um[win_nums[i]] = i+1;
    }
    for(auto e : lottos)
    {
        if(e == 0)
        {
            answer[0]--;  
        }
        else if(um[e])
        {
            answer[0]--;
            answer[1]--;
        }
    }
    for(auto& e : answer) if(e == 7) e--;
    return answer;
}