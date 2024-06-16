#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int k) {
    string answer;
    for (int i{}; i < k; i++) 
    {
        answer += my_string;
    }
    return answer;
}