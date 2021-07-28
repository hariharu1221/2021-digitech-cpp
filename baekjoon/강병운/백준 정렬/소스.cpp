#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<int, int> place;
	int N;
	int M;
	cout << "갯수 입력" << endl;

	cin >> N;

	cout << "요소 입력" << endl;

	for (int i = 0; i < N; ++i)
	{
		cin >> M;

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

