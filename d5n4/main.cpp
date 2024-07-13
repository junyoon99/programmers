#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;

    int a{1};
    int b{};

    for (auto e : num_list) 
    {
        a *= e;
        b += e;
    }
    b *= b;
    (a > b) ? answer = 0 : answer = 1;

    return answer;
}