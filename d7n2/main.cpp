#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;

    for (int i{ l }; i <= r; i++) 
    {
        string num = to_string(i);
        for (int i{}; i < num.size(); i++)
        {
            if (num[i] != '5' && num[i] != '0') break;
            if (i == num.size() - 1) answer.push_back(stoi(num));
        }
    }
    if (answer.empty())
    {
        answer.push_back(-1);
    }
    return answer;
}