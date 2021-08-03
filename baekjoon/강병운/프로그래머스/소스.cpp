#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
	int answer = 0;
	for (int i = 0; i < lost.size(); ++i)
	{
		for (int j = 0; j < reserve.size(); ++j)
		{
			if (lost[i] == reserve[j])
			{
				lost.erase(lost.begin() + i);
				reserve.erase(reserve.begin() + j);
			}
		}
	}

	for (int i = 0; i < lost.size(); ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			if (reserve.size() <= j)
			{
				if ((lost[i] - 1) + (j * 2) == reserve[0])
				{
					reserve.erase(reserve.begin() + 0);
					answer++;
					return answer;
				}

			}
			else if ((lost[i] - 1) + (j * 2) == reserve[j])
			{
				reserve.erase(reserve.begin() + j);
				answer++;
				break;
			}
		}
	}
		return n + answer - lost.size();
}

int main()
{
	vector<int> lost = { 2,4 };
	vector<int> reserve = { 3 };
	
	cout << solution(5, lost, reserve) << endl;

	return 0;
}