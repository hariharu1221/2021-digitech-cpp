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
	int N, M, down = 0, right = 0, x = 0, y = 0;
	cin >> N >> M;

	down = N - 8, right = M - 8;

	vector<string> chess(N);
	vector<int> W, B;

	W.resize(N + 1, 0);
	B.resize(N + 1, 0);

	for (size_t i = 0; i < N; i++)
		cin >> chess[i];

	// x : 0 -> right
	// y : 0 -> down

	// i : y -> 7 + y ( 8 )
	int i = y, j = x;
	for (; i < 8 + y; i++)
	{
		//cout << "\n" << "\n";
		//cout << "\t\ti loop : " << i << "\t" << y << "\n";
		// j : x -> 7 + x ( 8 )
		x = 0;
		for (j = x; j < 8 + x; j++)
		{
			// i + 1 : 홀수 -> 짝수 , 짝수 -> 홀수
			if ((i + 1) % 2 == 0) // 원래 i가 홀수
			{
				if ((j + 1) % 2 == 0) // 원래 j가 홀수
				{
					if (chess[i][j] != 'W')
						++W[i];
					else
						++B[i];
				}
				else // 짝수 ( 0도 포함 )
				{
					if (chess[i][j] != 'B')
						++B[i];
					else
						++W[i];
				}
			}
			else // 원래 i가 짝수 ( 0도 포함 )
			{
				if ((j + 1) % 2 == 0) // 원래 j가 홀수
				{
					if (chess[i][j] != 'B')
						++B[i];
					else
						++W[i];
				}
				else // 짝수 ( 0도 포함 )
				{
					if (chess[i][j] != 'W')
						++W[i];
					else
						++B[i];
				}
			}
			//cout << "j loop : " << j << "\t" << x << "\n";
			if (x < right && j == 7 + x)
				++x, j = x;
		}
		// 여기는 j가 right만큼 오른쪽으로 이동한후에 들어옴, 그래서 y를 더해서 내려줌
		if (y < down)
			++y;
	}

	return 0;
}