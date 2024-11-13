#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> hambuger{ 1,2,3,1 };
    stack<int> s;
    for (auto e : ingredient)
    {
        s.push(e);
        if (s.top() == 1 && s.size() > 3)
        {
            vector<int> sangsubuger(hambuger.size());
            for (int i{ static_cast<int>(hambuger.size()) -1 }; i >= 0; i--)
            {
                sangsubuger[i] = s.top();
                s.pop();
            }
            if (hambuger == sangsubuger) 
            {
                answer++;
            }
            else 
            {
                for (auto e : sangsubuger)
                {
                    s.push(e);
                }
            }
        }
    }
    return answer;
}