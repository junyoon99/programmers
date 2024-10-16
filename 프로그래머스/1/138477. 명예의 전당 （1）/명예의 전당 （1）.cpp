#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto e : score)
    {
        if(pq.size() < k)
        {
            pq.push(e);  
        } 
        else
        {
            if(pq.top() <= e)
            {
            pq.pop();
            pq.push(e);
            }
        }
        answer.push_back(pq.top());
    }
    
    return answer;
}