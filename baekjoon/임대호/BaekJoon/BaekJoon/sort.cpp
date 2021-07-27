#include <iostream>
#include <vector>

using namespace std;

// 인자로 넘겨받은 두 변수의 값을 바꿔주는 함수!
void Swap(int* v1, int* v2)
{
	int temp = *v1;
	*v1 = *v2;
	*v2 = temp;
}

int Sort1()
{
	// 입력받는 횟수!
	int count;
	cin >> count;

	// 입력받는 데이터를 저장하기 위한 vector!
	vector<int> v(count, 0);

	for (int i = 0; i < count; i++)
	{
		// 입력받는!
		cin >> v[i];

		// 이중 for문을 통해 vector의 맨 앞부터 대소 비교
		for (int j = 0; j < i; j++)
		{
			// 비교한 두 수 중 작은 수를 앞쪽으로 보냄
			if (v[j] > v[i])
			{
				Swap(&v[j], &v[i]);
			}
		}
	}

	// 출력하는 for문!
	for (int i = 0; i < count; i++)
	{
		cout << v[i] << endl;
	}

	return 0;
}
