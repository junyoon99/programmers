#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;

    for (int l{ left }; l <= right; l++)
    {
        int count{};
        for (int i{ 1 }; i <= l; i++)
        {
            if (!(l % i)) count++;
        }
        if (count & 1) answer -= l;
        else answer += l;
    }

    return answer;
}