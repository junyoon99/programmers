#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int count{};
    for(auto e : s)
    {
        if(e == 'p' || e == 'P') count++;
        if(e == 'y' || e == 'Y') count--;
    }
    if(!count) return true;
    else return false;
}