#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    
    int answer{};
    sort(d.begin(), d.end());
    for(auto e : d)
    {
        if(budget < e) break;
        budget -= e;
        answer++;
    }
    return answer;
}