#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int a{};
    int b{};
    for (int i{}; i < num_list.size(); i++)
    {
        if (num_list[i] % 2)
        {
            a *= 10;
            a += num_list[i];
        }
        else 
        {
            b *= 10;
            b += num_list[i];
        }
    }
    answer = a + b;
    return answer;
}