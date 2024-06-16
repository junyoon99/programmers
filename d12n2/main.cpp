#include <string>
#include <vector>
#include<iostream>
using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
	//queries�� ũ��� ���� ���͸� �����ϰ� 0���� �ʱ�ȭ <- ���� ��������� ���� ������ �� �� ��û ���Ƴ׿䤻��
	vector<int> answer(queries.size(), 0);
	
	//answer ��� �迭�� arr�� �ִ� �־����
	for (int i{}; i < queries.size(); i++) 
	{
		for (int k{}; k < arr.size(); k++)
		{
			if (answer[i] < arr[k]) answer[i] = arr[k];
		}
	}

	//queries�� ��� �迭�� �ݺ�
	for (int i{}; i < queries.size(); i++) 
	{
		bool isfind{};
		//arr�迭�� ��� ���� üũ
		for (int j{}; j < arr.size(); j++) 
		{
			//i�� s���� ũ�� e���� �۴�
			if ((j >= queries[i][0]) && (j <= queries[i][1])) 
			{
				//���� k���� ũ���� ���� ���� arr[i]�� ã�� ����Ѵ�
				if ((arr[j] > queries[i][2]) && (arr[j] <= answer[i]))
				{
					answer[i] = arr[j];
					isfind = true;
				}
			}
		}
		//��ã���� -1���
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

