#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    int gcd{};
    int copy_n{n};
    int copy_m{m};
    while(m!=0)
    {
        int remain = n % m;
        n = m;
        m = remain;
    }
    answer.push_back(n);
    answer.push_back(copy_n*copy_m / n);
    
    
    return answer;
}