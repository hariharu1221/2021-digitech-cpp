// 그리디 알고리즘이 맞는지는 확실하지 않습니다 ㅠㅠ
#include <iostream>

using namespace std;

int main()
{
	int count;
	cin >> count;

	int input;

	int arr1[4] = { 0, };
	int arr2[4] = { 25, 10, 5, 1 };

	for (int i = 0; i < count; i++)
	{
		cin >> input;
		while (input > 0)
		{
			if (arr2[0] <= input)
			{
				input -= arr2[0];
				arr1[0]++;
			}
			else if (arr2[1] <= input)
			{
				input -= arr2[1];
				arr1[1]++;
			}
			else if (arr2[2] <= input)
			{
				input -= arr2[2];
				arr1[2]++;
			}
			else if (arr2[3] <= input)
			{
				input -= arr2[3];
				arr1[3]++;
			}
			else break;
		}
		for (int i = 0; i < 4; i++)
		{
			cout << arr1[i] << " ";
			arr1[i] = 0;
		}
		cout << '\n';
	}

	return 0;
}