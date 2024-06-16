#include <string>
#include <vector>

using namespace std;

int solution(string ineq, string eq, int n, int m) {
    int answer = 0;

    if (n == m) 
    {
        if (eq == "!") return 0;
        else return 1;
    }

        if (n > m) 
        {
            if (ineq == ">") return 1;
            else return 0;
        }

        if (n < m) 
        {
            if (ineq == "<") return 1;
            else return 0;
        }
    return answer;
}