#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    if (n % 2) 
    {
        int i{ 1 };
        while (i <= n) 
        {
            answer += i;
            i += 2;
        }
    }
    else 
    {
        int i{ 0 };
        while (i <= n)
        {
            answer += i*i;
            i += 2;
        }
    }
    return answer;
}