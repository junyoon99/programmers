#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    for(int i{static_cast<int>(triangle.size())-2}; i >= 0; i--)
    {
        for(int j{}; j < triangle[i].size(); j++)
        {
            triangle[i][j] += max(triangle[i+1][j],triangle[i+1][j+1]);
        }
    }
    
    return triangle[0][0];
}