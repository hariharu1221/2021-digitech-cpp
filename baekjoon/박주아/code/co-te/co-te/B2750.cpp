#include "B2750.h"
#include <iostream>
#include <vector>
using namespace std;

char B2750::name[256] = "2750 - 수 정렬하기";
void B2750::answer()
{
	bool n[1001] = { false };
	bool m[1001] = { false };
	int k, l;
	vector<int> list;
	cin >> k;

	for (int i = 1; i <= k; i++)
	{
		cin >> l;
		if (l < 0) m[abs(l)] = true;
		else n[l] = true;
	}

	for (int i = 1000; i >= 1; i--)
		if (m[i]) list.push_back(-i);
	for (int i = 0; i <= 1000; i++)
		if (n[i]) list.push_back(i);

	for (auto &iter : list)
		cout << iter << endl;
}
