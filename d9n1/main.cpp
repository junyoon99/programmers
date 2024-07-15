#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
    vector<int> answer;

    for (auto e : intStrs) 
    {
        string a{};
        for (int i{}; i < l; i++) 
        {
            a += e[s + i];
        }
        if (stoi(a) > k) answer.push_back(stoi(a));
    }

    return answer;
}