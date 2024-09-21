#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int before;
    for(auto e : arr)
    {
        if(before != e) 
        {
         answer.push_back(e);
         before = e;   
        }
    }
    
    return answer;
}