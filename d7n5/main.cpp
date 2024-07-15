//d8n5문제임 d7n5문제는 d8n5에
#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) {

    for (auto e : queries) 
    {
        for (int i{}; i <= (abs(e[1] - e[0]) / 2); i++) 
        {
            swap(my_string[e[0] + i], my_string[e[1] - i]);
        }
    }

    return my_string;
}