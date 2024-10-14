#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int temp{};
    while(n >= a)
    {
        temp += n%a;
        n /= a;
        n *= b;
        answer += n;
        n += temp;
        temp = 0;
    }
    
    return answer;
}