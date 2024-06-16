#include <string>
#include <vector>
#include<iostream>
using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
	//queries의 크기와 같은 벡터를 생성하고 0으로 초기화 <- 벡터 생성방법을 몰라서 엉뚱한 곳 만 엄청 고쳤네요ㅋㅋ
	vector<int> answer(queries.size(), 0);
	
	//answer 모든 배열에 arr의 최댓값 넣어놓기
	for (int i{}; i < queries.size(); i++) 
	{
		for (int k{}; k < arr.size(); k++)
		{
			if (answer[i] < arr[k]) answer[i] = arr[k];
		}
	}

	//queries의 모든 배열을 반복
	for (int i{}; i < queries.size(); i++) 
	{
		bool isfind{};
		//arr배열의 모든 수를 체크
		for (int j{}; j < arr.size(); j++) 
		{
			//i는 s보다 크고 e보다 작다
			if ((j >= queries[i][0]) && (j <= queries[i][1])) 
			{
				//그중 k보단 크지만 가장 작은 arr[i]를 찾아 출력한다
				if ((arr[j] > queries[i][2]) && (arr[j] <= answer[i]))
				{
					answer[i] = arr[j];
					isfind = true;
				}
			}
		}
		//못찾으면 -1출력
		if (!isfind) answer[i] = -1;
	}

	return answer;
}

int main() 
{
	vector<int> arr = { 0, 1, 2, 4, 3 };
	vector<vector<int>> queries = { {0, 4, 2}, {0, 3, 2}, {0, 2, 2} };
	vector<int> result = solution(arr, queries);

	for (int i{}; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
}

