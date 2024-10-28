#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    int i{};
    for(auto e : section)
    {
        if(i < e)
        {
            ++answer;
            i  = e + m - 1;
        } 
    }
    
    return answer;
}