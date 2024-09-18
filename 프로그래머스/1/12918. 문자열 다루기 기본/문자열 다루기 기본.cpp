#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    if(s.size() == 4 || s.size() == 6)
    {
        for(auto e : s)
        {
            if(!(e >= '0' && e <= '9')) return false;
        }
        return true;
    }
    return false;
}