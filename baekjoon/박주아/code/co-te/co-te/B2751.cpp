#include "B2751.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char B2751::name[256] = "2751 - 수 정렬하기2";
void B2751::answer()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	static bool m[2000001] = { false };
	int n,l;
	cin >> n;
	vector<int> list;

	for (int i = 0; i < n; i++)
	{
		cin >> l;
		if (m[1000000 + l] == false)
			list.push_back(l);
		m[1000000 + l] = true;
	}
	sort(list.begin(), list.end());

	for (auto& iter : list)
		cout << iter << endl;
}