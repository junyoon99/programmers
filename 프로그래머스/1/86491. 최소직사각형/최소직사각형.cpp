#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int width{};
    int hight{};
    
    for(auto e : sizes)
    {
        if(e[0] < e[1]) swap(e[0], e[1]);
        width = max(width, e[0]);
        hight = max(hight,e[1]);
    }
    
    answer = width*hight;
    return answer;
}