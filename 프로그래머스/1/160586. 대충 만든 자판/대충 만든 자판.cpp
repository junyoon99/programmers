#include <string>
#include <vector>
#include <climits>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer(targets.size(), 0);

    for (int i{}; i < targets.size(); i++)
    {
        int count{};
        for (auto e : targets[i])
        {
            char t{ e };
            int idx{INT_MAX};
            for (auto f : keymap)
            {
                for (int j{}; j < f.size(); j++) 
                {
                    if (f[j] == t)
                    {
                        idx = min(idx, j+1);
                        break;
                    }
                }
            }
            if (idx == INT_MAX) 
            {
                answer[i] = -1;
                break;
            }
            else 
            {
                answer[i] += idx;
            }
        }
    }
    return answer;
}