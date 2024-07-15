#include <string>
#include <vector>

using namespace std;

int solution(string number) {
    int answer{};

    for (auto e : number) 
    {
        answer += e-48;
    }
    while ((answer / 9) != 0) 
    {
        if (answer == 9) return 0;
        string a = to_string(answer);
        answer = 0;
        for (auto e : a)
        {
            answer += e-48;
        }
    }
    
    return answer;
}

int main() 
{
    solution("78720646226947352489");
}