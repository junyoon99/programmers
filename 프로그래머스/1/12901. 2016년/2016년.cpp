#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {    
    vector<int> month{31,29,31,30,31,30,31,31,30,31,30,31};
    vector<string> week{"SUN","MON","TUE","WED","THU","FRI","SAT"};
    int lastyearlastday{4};
    for(int i{}; i < a-1;i++)
    {
        lastyearlastday += month[i];
    }
    lastyearlastday += b;
    return week[lastyearlastday%7];
}