#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;
using ll = long long;

void QuickSort(vector<ll>& v, int low, int high)
{
	if (low >= high) return;

	int i = low, j = low;
	ll& pivot = v[high];
	for (; j < high; j++)
		if (v[j] < pivot)
			swap(v[i++], v[j]);
	swap(v[i], pivot);

	QuickSort(v, low, i - 1);
	QuickSort(v, i + 1, high);
}

void HeapSort(vector<ll>& v)
{
	int c, root;
	for (size_t i = 1; i < v.size(); i++)
	{
		c = i;
		do
		{
			root = (c - 1) / 2;
			if (v[root] < v[c])
				swap(v[root], v[c]);
			c = root;
		} while (c != 0);
	}

	for (int i = v.size() - 1; i >= 0; i--)
	{
		swap(v[i], v[0]);
		root = 0;
		c = 1;
		do
		{
			c = 2 * root + 1;
			if (c < i - 1 && v[c] < v[c + 1])
				c++;
			if (c < i && v[root] < v[c])
				swap(v[root], v[c]);
			root = c;
		} while (c < i);
	}
}

int main()
{
	ll N;
	cin >> N;
	N = 1000000;

	vector<ll> v(N);

	int val;

	for (size_t i = 0; i < N; i++)
	{
		//cin >> val;
		v[i] = i;
	}

	auto start = system_clock::now();

	HeapSort(v);

#pragma region time
	auto end = system_clock::now();

	auto total_time = end - start;

	cout << duration_cast<milliseconds>(total_time).count() << "ms" << endl;
#pragma endregion

	//for (auto& iter : v)
	//	cout << iter << endl;

	return 0;
}