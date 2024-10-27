#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;

    vector<bool> sosu(3000, true);
    for (int i{ 2 }; i < sosu.size(); ++i)
    {
        if (sosu[i])
        {
            int j{2};
            while (i * j < sosu.size())
            {
                sosu[i*j] = false;
                ++j;
            }
        }
    }

    for (int i{}; i < nums.size(); ++i)
    {
        for (int j{ i + 1 }; j < nums.size(); ++j)
        {
            for (int k{ j + 1 }; k < nums.size(); ++k)
            {
                answer += sosu[nums[i] + nums[j] + nums[k]];
            }
        }
    }

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}