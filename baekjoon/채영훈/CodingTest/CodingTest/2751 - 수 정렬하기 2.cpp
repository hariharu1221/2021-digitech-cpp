#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <algorithm>
#include <chrono>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> v(N);

	for (size_t i = 0; i < N; i++)
		cin >> v[i];

	stable_sort(v.begin(), v.end());

	for (auto& iter : v)
		cout << iter << "\n";

	return 0;
}