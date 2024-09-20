#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {

	int row{ (int)park.size() };
	int col{ (int)park[0].size() };
	vector<vector<int>> table(row, vector<int>(col, 0));
	int answer = 0;

	for (int i{}; i < row; i++) 
	{
		for (int j{}; j < col; j++) 
		{
			if (park[i][j] == "-1") 
			{
				if (i == 0 || j == 0) 
				{
					table[i][j] = 1;
				}
				else 
				{
					table[i][j] = min( table[i - 1][j], table[i][j - 1] );
                    table[i][j] = min( table[i][j], table[i - 1][j - 1] ) + 1;
				}

				answer = max(answer, table[i][j]);
			}
		}
	}
	int temp{-1};
	for (auto e : mats)
	{
		if (e <= answer) temp = max(e, temp);
	}
	return temp;
}  