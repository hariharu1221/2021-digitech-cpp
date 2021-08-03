#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <chrono>
#include "TripleLong.h"

using namespace std;
using ll = long long;

int main()
{
	TripleLong tl1;
	TripleLong tl2;
	TripleLong tl3;

	tl1.SetVal("10000000");
	tl2.SetVal("300000");

	tl3 = tl1 + tl2;

	cout << tl3.GetVal() << endl;

	//int N;
	//cin >> N;

	//ll left = 1, right = N, mid = 0, val = 0, result = 2;

	//while (left <= right)
	//{
	//	mid = (left + right) / 2;
	//	val = mid * mid;
	//	if (val > N)
	//		right = mid - 1, result = mid;
	//	else
	//		left = mid + 1;
	//}

	//cout << result - 1 << "\n";

	return 0;
}