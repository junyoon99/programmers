#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    unordered_map<int, bool> um;
    
    for(int i{}; i < nums.size(); i++)
    {
        if(!um[nums[i]])
        {
            um[nums[i]] = true;
            answer++;
        }
        if(answer == nums.size()/2) break;
    }
    
    return answer;
}