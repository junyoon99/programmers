#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> arr) {
    string answer;
    for (int i{}; i < arr.size(); i++) 
    {
        answer += arr[i];
    }
    
    return answer;
}

int main() 
{
    
}