#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.begin(), score.end(), greater<int>());
    for(int i{}; i < score.size(); i += m)
    {
        if(i+m-1 >= score.size() || score[i] > k) break;
        answer += score[i+m-1]*m;
    }
    
    return answer;
}