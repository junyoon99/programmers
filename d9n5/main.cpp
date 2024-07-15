#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_suffix) {
    int answer = 0;
    for (int i{}; i < my_string.length(); i++) 
    {
        if (my_string.substr(i) == is_suffix) return 1;
    }
    return answer;
}