#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    
    for(auto &e : s)
    {
        if(e >= 'a' && e <= 'z')
        {
            if(e + n > 'z') 
            {
                e += n - ('z'-'a'+1);
            }
            else e += n;
        }
        else if(e >= 'A' && e <= 'Z')
        {
            if(e + n > 'Z') 
            {
                e += n - ('Z'-'A'+1);
            }
            else e += n;
        }
    }
    
    return s;
}