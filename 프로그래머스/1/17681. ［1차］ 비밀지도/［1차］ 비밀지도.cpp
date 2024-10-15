#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n, string(n,' '));
    for (int i{}; i < arr1.size(); i++)
    {
        int temp{ arr1[i] | arr2[i] };
        for (int j{}; j < n; j++) 
        {
            answer[i][n-1-j] = (temp % 2 + '0' == '1') ? '#' : ' ';
            temp /= 2;
        }
    }

    return answer;
}