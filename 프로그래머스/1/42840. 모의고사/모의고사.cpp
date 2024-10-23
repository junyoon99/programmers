#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> vec(3,0);
    vector<int> h1{1,2,3,4,5};
    vector<int> h2{2,1,2,3,2,4,2,5};
    vector<int> h3{3,3,1,1,2,2,4,4,5,5};
    for(int i{}; i < answers.size(); i++)
    {
        if(h1[i%h1.size()] == answers[i]) vec[0]++;
        if(h2[i%h2.size()] == answers[i]) vec[1]++;
        if(h3[i%h3.size()] == answers[i]) vec[2]++;
    }
    int highest{-1};
    for(int i{}; i < 3; i++)
    {
        if(highest < vec[i])
        {
            answer.clear();
            highest = vec[i];
            answer.push_back(i+1);
        }
        else if(highest == vec[i])
        {
            answer.push_back(i+1);
        }
    }
    
    return answer;
}