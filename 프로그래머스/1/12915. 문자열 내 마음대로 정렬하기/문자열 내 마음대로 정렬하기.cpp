#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    sort(strings.begin(), strings.end(),[n](string a, string b)->bool{
        if(a[n] == b[n])
        {
           int s{};
            while(a[s] == b[s]) s++;
            return a[s] < b[s];
        }
        return a[n] < b[n];
    });
    
    return strings;
}