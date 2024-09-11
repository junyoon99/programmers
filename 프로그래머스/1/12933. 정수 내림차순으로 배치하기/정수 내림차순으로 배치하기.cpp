#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string nn = to_string(n);
    sort(nn.begin(), nn.end(),
        [](int a, int b) -> bool 
        {return a > b; }
    );
    answer = stoll(nn);
    return answer;
}