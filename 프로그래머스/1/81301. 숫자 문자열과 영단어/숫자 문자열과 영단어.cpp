#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string s) {
    int answer = 0;
    unordered_map<string, int> table;

    table["zero"] = 1;
    table["one"] = 2;
    table["two"] = 3;
    table["three"] = 4;
    table["four"] = 5;
    table["five"] = 6;
    table["six"] = 7;
    table["seven"] = 8;
    table["eight"] = 9;
    table["nine"] = 10;

    string Temp;
    string SAnswer;

    for (auto e : s)
    {
        if (e >= '0' && e <= '9')
        {
            SAnswer.push_back(e);
        }
        else
        {
            Temp.push_back(e);
            if (table[Temp])
            {
                SAnswer += to_string(table[Temp] - 1);
                Temp.clear();
            }
        }
    }
    return stoi(SAnswer);
}