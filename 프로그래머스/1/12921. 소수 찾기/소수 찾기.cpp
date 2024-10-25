#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> vec(n+1,0);
    
    for(int i{2}; i < vec.size(); i++)
    {
        int j{1};
        while(i*j < vec.size())
        {
            vec[i*j]++;
            j++;
        }
    }
    for(auto e : vec)
    {
        if(e == 1) answer++;
    }
    
    return answer;
}