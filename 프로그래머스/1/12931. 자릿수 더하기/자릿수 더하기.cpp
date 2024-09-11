#include <iostream>
#include <cmath>

using namespace std;
int solution(int n)
{
    int answer = 0;
    int copy{ n };
    int count{};

    while (copy / 10 != 0)
    {
        copy /= 10;
        count++;
    }
    while (count)
    {
        int i{};
        i = n / pow(10, count);
        answer += i;
        n -= pow(10, count)*i;
        count--;
    }
    answer += n;
    return answer;
}