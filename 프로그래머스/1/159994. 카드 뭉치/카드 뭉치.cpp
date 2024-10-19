#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    queue<string> q;
    for(auto e : cards1)
    {
        q.push(e);
    }
    queue<string> q2;
    for(auto e : cards2)
    {
        q2.push(e);
    }
    
    for(auto e : goal)
    {
        if(e == q.front())
        {
            q.pop();
        }
        else if(e == q2.front())
        {
            q2.pop();
        }
        else return "No";
    }
    
    return "Yes";
}