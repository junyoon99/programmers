#include <string>
#include <vector>

using namespace std;

int solution(int n, string control) {
    int answer = 0;

    for (auto e : control) 
    {
        switch (e)
        {
        case 'w':
            n++;
            break;

        case 's':
            n--;
            break;

        case 'd':
            n+=10;
            break;

        case 'a':
            n-=10;
            break;

        default:
            break;
        }
    }
    answer = n;
    return answer;
}