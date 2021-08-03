#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <chrono>

using namespace std;
using ll = long long;

int main()
{
	ll X, Y, Z = 0, left = 1, right = 1000000000, mid = 0, per = 0, add = -1;
	
	cin >> X >> Y;

	// Z = 원래한 게임의 total의 승리한 %
	Z = ll(Y * 100 / X);

	// Z가 99보다 작다면 while문이 돌고 아니라면 -1인 add를 print
	if (Z < 99)
	{
		// right가 left를 넘어갈때에, left가 right를 넘어갈때에 종료
		while (left <= right)
		{
			// mid = left와 right의 중심값
			mid = (left + right) / 2;

			// val = X와 Y에 mid가 더해진 보정된 %
			per = (Y + mid) * 100 / (X + mid);

			// mid가 더해져 보정된 %가 Z보다 클 경우
			if (per > Z) // right = mid에서 1을 뺀 곳을 오른쪽으로 갱신, add에 보정값 mid를 저장
				right = mid - 1, add = mid;
			else // left = mid에서 1을 더한 곳을 왼쪽으로 갱신
				left = mid + 1;
		}
	}

	// add값을 print
	cout << add << "\n";

	return 0;
}