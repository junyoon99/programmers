#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> s;
    
    while(n > 0)
    {
        s.push_back(n%3);
        n /= 3;
    }
    
    int a{};
    
    for(int i{(int)s.size()-1}; i >= 0; i--)
    {
        answer += s[i]*pow(3,a);
        a++;
    }
    
    return answer;
}