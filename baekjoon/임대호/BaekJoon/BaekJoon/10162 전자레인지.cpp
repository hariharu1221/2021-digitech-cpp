// 그리디 알고리즘이 맞는지는 확실하지 않습니다 ㅠㅠ
#include <iostream>

using namespace std;

int 전자레인지()
{
	int n, arr1[3] = { 0, }, arr2[3] = { 300,  60, 10 };
	cin >> n;

	while (n > 0)
	{
		if (arr2[0] <= n)
		{
			n -= arr2[0];
			arr1[0]++;
		}
		else if (arr2[1] <= n)
		{
			n -= arr2[1];
			arr1[1]++;
		}
		else if (arr2[2] <= n)
		{
			n -= arr2[2];
			arr1[2]++;
		}
		else
		{
			cout << -1;
			return 0;
		}
	}

	for (int i = 0; i < 3; i++)
		cout << arr1[i] << " ";

	return 0;
}