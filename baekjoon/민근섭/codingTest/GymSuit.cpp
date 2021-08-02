#include <iostream>	
#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserves);

int main()
{
	vector<int> lost;
	lost.push_back(2);
	lost.push_back(4);
	vector<int> reserve;
	reserve.push_back(1);
	reserve.push_back(3);
	reserve.push_back(5);
	solution(5, lost, reserve);
	return 0;
}

int solution(int n, vector<int> lost, vector<int> reserves)
{
	int answer = 0;
	int students[30];
	for (int i = 0; i < 30; i++)
	{
		students[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		students[i] = 1;
	}

	for (int i = 0; i < lost.size(); i++)
	{
		students[lost[i]] --;
	}

	for (int i = 0; i < reserves.size(); i++)
	{
		students[reserves[i]] ++;
	}

	for (int i = 0; i < n; i++)
	{
		if (students[i] == 2)
		{
			if (students[i + 1] == 0 && i + 1 < n)
			{
				students[i + 1]++;
				students[i]--;
			}
			else if (i - 1 >= 0 && students[i - 1] == 0)
			{
				students[i - 1]++;
				students[i]--;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (students[i] > 0)
		{
			answer++;
		}
	}
	cout << answer << endl;
	return answer;
}