#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer{arr};
    for (int i{}; i < queries.size(); i++) 
    {
        int temp{ answer[queries[i][1]] };
        answer[queries[i][1]] = answer[queries[i][0]];
        answer[queries[i][0]] = temp;
    }
    return answer;
}