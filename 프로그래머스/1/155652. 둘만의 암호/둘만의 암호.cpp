#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(string s, string skip, int index) {
    unordered_map<char, bool> um;
    for(auto e : skip)
    {
        um[e] = true;
    }
    for(auto& e : s)
    {
        for(int i{}; i < index; i++)
        {
            e++;
            e = e > 'z' ? e - ('z'-'a'+1) : e;
            if(um[e]) i--;
        }
    }
    return s;
}