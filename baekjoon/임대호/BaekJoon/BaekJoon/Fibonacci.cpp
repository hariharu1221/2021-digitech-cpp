#include <iostream>
#include <vector>

using namespace std;

int Fibonacci1()
{
	// 입력받은 수
	int input;
	cin >> input;

	// 연산 결과들을 저장할 vector!
	vector<int> v(45, 0);
	v[0] = 0;
	v[1] = 1;

	// 연산을 하는 for문!
	for (int i = 2; i <= input; i++)
	{
		v[i] = v[i - 1] + v[i - 2];
	}

	cout << v[input];
	return 0;
}
