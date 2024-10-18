#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    unordered_map<string, int> um;
    for(int i{}; i < name.size(); i++)
    {
        um[name[i]] = yearning[i];
    }
    
    for(auto e : photo)
    {
        int temp{};
        for(auto f : e)
        {
            temp += um[f];
        }
        answer.push_back(temp);
    }
    
    return answer;
}