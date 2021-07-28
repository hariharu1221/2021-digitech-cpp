#include <iostream>
#include <map>
#include <math.h>

using namespace std;

int main()
{
	map<int, int> place;
	int N;
	int M;
	do
	{
		cout << "갯수 입력" << endl;

		cin >> N;

	} while (N < 1 || N>1000);

	cout << "요소 입력" << endl;

	for (int i = 0; i < N; ++i)
	{
		do
		{
			cin >> M;
		} while (abs(M) > 1000);

		place.insert(pair<int, int>(M, M));
	}

	cout << endl << "요소 정렬 & 출력" << endl;

	map<int, int>::iterator iter;

	for (iter = place.begin(); iter != place.end(); iter++)
	{
		cout << (*iter).second << endl;
	}

	return 0;

}

