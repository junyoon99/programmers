//d7n5문제임 d8n5는 d7n5에

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> stk;
    int i{};

    while (i < arr.size())
    {
        if (!stk.size())
        {
            stk.push_back(arr[i]);
            i++;
        }
        else if (stk.back() < arr[i])
        {
            stk.push_back(arr[i]);
            i++;
        }
        else
        {
            stk.pop_back();
        }
    }

    return stk;
}

int main() 
{
    vector<int> arr{ 1,4,2,5,3 };
    solution(arr);
}