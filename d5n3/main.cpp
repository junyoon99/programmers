#include <string>
#include <vector>
#include<cmath>
#include<iostream>

using namespace std;

int solution(int a, int b, int c) {
    int answer = a + b + c;
    if ((a == b) || (b == c) || (a == c)) 
    {
        answer *= pow(a, 2) + pow(b, 2) + pow(c, 2);
        if ((a == b) && (b == c)) 
        {
            answer *= pow(a, 3) + pow(b, 3) + pow(c, 3);
        }
    }
    
    return answer;
}

int main() 
{
    std::cout << solution(4, 4, 4);
}