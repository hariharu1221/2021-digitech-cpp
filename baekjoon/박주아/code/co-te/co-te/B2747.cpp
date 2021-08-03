#include "B2747.h"
#include <iostream>
using namespace std;

char B2747::name[256] = "2747 - 파보나치 수";
void B2747::answer()
{
	int n;
	int list[50] = { 0 };
	cin >> n;
	for (int i = 0; i <= n; i++)
	{
		if (i < 2)
		{
			list[i] = i;
			continue;
		}
		list[i] = list[i - 1] + list[i - 2];
	}
	n = list[n];
	cout << n << endl;
}
