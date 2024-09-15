#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> sides) {
    unordered_map<int, bool> check;
    
    for(int i{max(sides[0], sides[1]) + 1}; i < sides[0] + sides[1]; i++)
    {
        check[i] = true;
    }
    
    for(int i{abs(sides[0] - sides[1]) + 1}; i <= max(sides[0], sides[1]); i++)
    {
        check[i] = true;
    }
    
    return check.size();
}