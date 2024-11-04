#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    vector<pair<int,int>> vec(2,{-1,0});
    for(auto e : s)
    {
        if(vec[0].first == -1)
        {
            vec[0].first = e;
        }
        if(e == vec[0].first)
        {
            vec[0].second++;
        }
        else
        {
            vec[1].second++;
        }
        if(vec[0].second == vec[1].second)
        {
            answer++;
            vec[0].first = -1;
            vec[0].second = 0;
            vec[1].second = 0;
        }
    }
    if(vec[0].first != -1) answer++;
    return answer;
}