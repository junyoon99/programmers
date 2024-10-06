#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    unordered_map<int,bool> check;
    
    for(int i{}; i < numbers.size(); i++)
    {
        for(int j{i+1}; j < numbers.size(); j++)
        {
            if(!check[numbers[i]+numbers[j]])
            {
                check[numbers[i]+numbers[j]] = true;
                answer.push_back(numbers[i]+numbers[j]);
            }
        }
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}