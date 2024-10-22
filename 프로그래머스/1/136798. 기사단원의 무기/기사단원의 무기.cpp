#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    
    vector<int>vec(number+1,1);
    for(int i{1}; i <= number; i++)
    {
        for(int j{2}; j <= number; j++)
        {
            if(i*j > number) break;
            else vec[i*j]++;
        }
    }
    for(auto e : vec)
    {
        if(e > limit) answer += power;
        else answer += e;
    }
        
    return answer-1;
}