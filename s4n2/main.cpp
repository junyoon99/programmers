#include <string>
#include <vector>

using namespace std;

int solution(int number, int n, int m) {
    int answer = 0;

    if ((number % n) || (number % m)) answer = 0;
    else answer = 1;

    return answer;
}