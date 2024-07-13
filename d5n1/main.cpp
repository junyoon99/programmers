#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string code) {
    bool mode{};
    string answer = "";

    for (int i{}; i < code.size(); i++) 
    {
        if (!mode)
        {
            if (code[i] == '1') mode = 1;
            else if (!(i % 2)) answer += code[i];
        }
        else
        {
            if (code[i] == '1') mode = 0;
            else if (i % 2) answer += code[i];
        }
    }
    if (answer.size() == 0) answer = "EMPTY";
    return answer;
}

int main() 
{
    string a = "";
    std::cout << solution(a);
}