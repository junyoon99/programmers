#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    vector<vector<int>> sum(triangle.size(), vector<int>(triangle[triangle.size()-1].size(),0));
    sum[0][0] = triangle[0][0];
    for(int i{1}; i < triangle.size(); i++)
    {
        for(int j{}; j < triangle[i].size(); j++)
        {
            if(j == 0)
            {
                sum[i][j] = triangle[i][j] + sum[i-1][j];
            }
            if(j == triangle[i].size()-1)
            {
                sum[i][j] = triangle[i][j] + sum[i-1][j-1];
            }
            else
            {
                sum[i][j] = max(triangle[i][j] + sum[i-1][j-1], triangle[i][j] + sum[i-1][j]);
            }
        }
    }
    
    return *(max_element(sum[sum.size()-1].begin(),sum[sum.size()-1].end()));
}