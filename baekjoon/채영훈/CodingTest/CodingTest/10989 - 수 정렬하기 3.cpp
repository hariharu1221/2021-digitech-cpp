#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <algorithm>
#include <chrono>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	vector<int> v(10001);

	int temp;
	for (int i = 0; i < N; ++i)
	{
		cin >> temp;
		++v[temp];
	}

	for (int i = 1; i <= 10000; ++i)
		for (int j = 0; j < v[i]; ++j)
			cout << i << "\n";

	return 0;
}