#include <string>
#include <vector>
#include<iostream>

using namespace std;

int solution(int a, int d, vector<bool> included) {
	int size = included.size();
	std::vector<int> A(size);
	int index = a;
	int answer = 0;
	for (int i{}; i < size; i++)
	{
		if (included[i])
		{
			A[i] = a;
		}
		else A[i] = 0;
		answer += A[i];
		a += d;
	}
	
	return answer;
}

int main() 
{
	std::vector<bool> included{ true,false,false ,true,true };
	std::cout << solution(3, 4, included);
}