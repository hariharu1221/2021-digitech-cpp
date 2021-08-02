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
	int N, M, down = 0, right = 0;
	cin >> N >> M;

	down = N - 8, right = M - 8;

	vector<string> chess(N);
	vector<int> W, B;

	W.resize(down * right + 1, 0);
	B.resize(down * right + 1, 0);

	for (size_t i = 0; i < N; i++)
		cin >> chess[i];

	int x = 0;
	int y = 0;
	for (size_t i = y; i < 8 + y;)
	{
		for (size_t j = x; j < 8 + x;)
		{
			// ------- W 의 조건 ----------
			if ((i + 1) % 2 == 1)
			{
				if ((j + 1) % 2 == 1) // W의 조건
				{
					if (chess[i][j] != 'W')
						++W[y * right + x];
					else
						++B[y * right + x];
				}
				else // B의 조건
				{
					if (chess[i][j] != 'B')
						++W[y * right + x];
					else
						++B[y * right + x];
				}
			}
			else
			{
				if ((j + 1) % 2 == 0)// W의 조건
				{
					if (chess[i][j] != 'W')
						++W[y * right + x];
					else
						++B[y * right + x];
				}
				else // B의 조건
				{
					if (chess[i][j] != 'B')
						++W[y * right + x];
					else
						++B[y * right + x];
				}
			}
			j++;
			if (x + 1 < right && j == 8 + x) ++x, j = x;
		}
		i++;
		if (y + 1 < down && i == 8 + y) ++y, i = y, x = 0;
	}

	return 0;
}