#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string name);

int main()
{
	solution("JEROEN");
	return 0;
}

int solution(string name)
{
	int answer = 0;
	int index = 0;
	string initialName;
	for (int i = 0; i < name.length(); i++)
	{
		initialName += "A";
	}

	while (true)
	{
		answer += min(name[index] - 'A', 'Z' - name[index] + 1);
		initialName[index] = name[index];

		if (initialName == name)
		{
			cout << answer << endl;
			return answer;
		}

		int left = index;
		int leftCnt = 0;
		while (initialName[left] == name[left])
		{
			left--;
			leftCnt++;
			if (left == -1)
				left = name.size() - 1;
		}

		int right = index;
		int rightCnt = 0;
		while (initialName[right] == name[right])
		{
			right++;
			rightCnt++;
			if (right == name.size())
				right = 0;
		}

		if (leftCnt < rightCnt)
		{
			answer += leftCnt;
			index = left;
		}
		else
		{
			answer += rightCnt;
			index = right;
		}
	}
	return answer;
}

