#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> v(2001, -3000);

	int val;
	for (int i = 0; i < N; i++)
	{
		cin >> val;
		if (val <= 0)
			v[abs(val)] = val;
		else
			v[val + 1000] = val;
	}

	reverse(v.begin(), v.begin() + 1001);

	auto remove = remove_if(v.begin(), v.end(), [](int n) {return n == -3000; });
	v.resize(remove - v.begin());

	for (auto& iter : v)
		cout << iter << endl;

	return 0;
}