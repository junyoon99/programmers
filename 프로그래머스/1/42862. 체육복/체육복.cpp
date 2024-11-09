#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> vec(n, 1);
    for (auto e : lost) 
    {
        vec[e - 1]--;
    }
    for (auto e : reserve) 
    {
        vec[e-1]++;
    }
    for (int i{}; i < vec.size(); i++) 
    {
        if (vec[i] > 1) 
        {
            if (i > 0 && vec[i - 1] < 1) 
            {
                vec[i - 1]++;
                vec[i]--;
            }
            else if (i < vec.size()-1 && vec[i + 1] < 1) 
            {
                vec[i + 1]++;
                vec[i]--;
            }
        }
    }
    int count{};
    for (auto e : vec) 
    {
        if (e < 1) 
        {
            count++;
        }
    }
    return n - count;
}