#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<bool> vec(n+1,true);
    
    for(int i{2}; i < vec.size(); i++)
    {
        if(vec[i])
        {
            int j{1};
            answer++;
            while(i*j < vec.size())
            {
                vec[i*j] = false;
                j++;
            }  
        } 
    }
    return answer;
}