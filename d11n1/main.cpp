#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer(52,0);

    for (auto e : my_string) 
    {
        if (int('A') <= e && int('Z') >= e) answer[int(e) - int('A')]++;
        else if(int('a') <= e && int('z') >= e) answer[int(e) - int('A') - 6]++;
    }

    return answer;
}

int main() 
{
    solution("asdf");
}