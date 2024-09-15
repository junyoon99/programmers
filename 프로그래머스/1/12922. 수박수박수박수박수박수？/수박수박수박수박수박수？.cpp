#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    string watermelon = "수박";

    for (int i{}; i < n; i++)
    {
        if (i & 1) answer += watermelon.substr(3, 3);
        else answer += watermelon.substr(0, 3);
    }

    return answer;
}