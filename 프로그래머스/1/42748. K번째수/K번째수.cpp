#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(auto e : commands)
    {
        vector<int> Subvec(array.begin()+e[0]-1, array.begin()+e[1]);
        sort(Subvec.begin(), Subvec.end());
        answer.push_back(Subvec[e[2]-1]);
    }
    
    return answer;
}