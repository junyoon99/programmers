#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    
    for(int i{min(a, b)}; i <= max(b,a); i++)
    {
        answer += i;
    }
    
    return answer;
}