#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    
    long long i{};
    while(n)
    {
        i += x;
        answer.push_back(i);
        --n;
    }
    
    return answer;
}