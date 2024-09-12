#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int j{x};
    int i{};
    while(int(x/10))
    {
        i += x%10;
        x /= 10;
    }
    i += x;
    
    return !(int(j%i));
}