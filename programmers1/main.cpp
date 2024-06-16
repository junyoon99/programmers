#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int a, int b) {

    int q{ a };
    int w{ b };
    int e{1};
    int r{1};
    int answer{};

    while (q > 9) 
    {
        q /= 10;
        e++;
    }
    while (w > 9) 
    {
        w /= 10;
        r++;
    }

    int answer1{};
    int answer2{};
    answer1 = b*pow(10, e) + a;
    answer2 = a*pow(10, r) + b;

    //std::cout << answer1 << std::endl << answer2 << std::endl;

     if (answer1 > answer2) return answer1;
     else return answer2;
}

int main()
{
    std::cout << solution(9, 91);
}