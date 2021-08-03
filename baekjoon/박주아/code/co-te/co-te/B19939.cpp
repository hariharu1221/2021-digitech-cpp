#include "B19939.h"
#include <iostream>
using namespace std;

char B19939::name[256] = "19939 - ¹Ú ÅÍ¶ß¸®±â";
void B19939::answer()
{
	int n, k, sum = 0;
	cin >> n, cin >> k;
	for (int i = 0; i <= k; i++)
		sum += i;
	if ((n - sum) < 0) cout << "-1" << endl;
	else
	{
		if ((n - sum) % k == 0) cout << k - 1 << endl;
		else cout << k << endl;
	}
}