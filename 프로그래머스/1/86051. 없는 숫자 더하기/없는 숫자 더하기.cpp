#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer{};
    int i{};
    for(int i{}; i < 10; i++)
    {
        answer += i;
    }
    for(auto e : numbers)
    {
        i += e;
    }
    
    return answer-i;
}