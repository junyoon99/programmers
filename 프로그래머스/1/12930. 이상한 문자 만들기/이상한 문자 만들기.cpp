#include <string>
#include <vector>
#include <cctype>
using namespace std;

string solution(string s) {
    
    int a{};
    for(int i{}; i < s.size(); i++)
    {
        if(s[i] == ' ') 
        {
            a = 0;
        }
        else if(a%2) 
        {
            s[i] = tolower(s[i]);
            a++;
        }
        else 
        {
            s[i] = toupper(s[i]);
            a++;   
        }
    }
    
    return s;
}