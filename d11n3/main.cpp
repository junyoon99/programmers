#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string my_string, vector<int> indices) {

    for (auto e : indices)
    {
        my_string.erase(my_string.begin()+e);
        for (auto& r : indices) 
        {
            if (r > e) r--;
        }
    }

    return my_string;
}

int main() 
{
    std::cout << solution("asdf", { 0,1,2 });
}