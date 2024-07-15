#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int a, int b, int c, int d) {

	int answer = 0;
	vector<int> nums{a,b,c,d};
	int count{};
	int diff{};
	for (int i{}; i < nums.size(); i++) 
	{
		for (int j{}; j < nums.size(); j++) 
		{
			if (nums[i] == nums[j]) count++;
			else { diff = nums[j]; }
		}
		if (count == 4) return answer = 1111 * nums[i];
		else if (count == 3) return answer = pow((10*nums[i] + diff), 2);
		else if (count == 2) 
		{
			int diff2{};
			for (auto e : nums)
			{
				if ((nums[i] != e) && (e != diff)) diff2 = e;
			}
			if (diff2) return answer = diff * diff2;
			else return answer = (nums[i] + diff) * abs(nums[i] - diff);
		}
		count = 0;
	}
	if (!answer) 
	{
		int min{nums[0]};
		for (int i{}; i < nums.size(); i++) 
		{
			if (min > nums[i]) min = nums[i];
		}
		answer = min;
	}
	return answer;
}