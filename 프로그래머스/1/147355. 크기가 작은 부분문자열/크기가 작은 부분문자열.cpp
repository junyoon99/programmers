#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    int t_size = static_cast<long long>(t.size());
    int p_size = static_cast<long long>(p.size());
    
    for(int i{}; i <= t_size - p_size; i++)
    {
        if(stoll(t.substr(i,p_size)) <= stoll(p)) answer++;
    }
    
    return answer;
}