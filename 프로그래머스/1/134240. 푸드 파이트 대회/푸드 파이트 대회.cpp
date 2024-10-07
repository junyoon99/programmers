#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    stack<int> s;
    for(int i{1}; i < food.size(); i++)
    {
        while(food[i] > 1)
        {
            answer.push_back(i+'0');
            s.push(i+'0');
            food[i] -= 2;
        }
    }
    answer.push_back('0');
    while(!s.empty())
    {
        answer.push_back(s.top());
        s.pop();
    }
    
    return answer;
}