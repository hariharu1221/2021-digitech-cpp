#include <iostream>

using namespace std;

int main()
{
	int time;

	int cent[500];
	const int A = 25;
	const int B = 10;
	const int C = 5;
	const int D = 1;

	int aTime = 0;
	int bTime = 0;
	int cTime = 0;
	int dTime = 0;

	cin >> time;

	for (int i = 0; i < time; i++)
	{
		cin >> cent[i];
	}

	for (int t = 0; t < time; t++)
	{
		if (cent[t] >= A)
		{
			for (int i = cent[t]; i >= A; i -= A)
			{
				cent[t] -= A;
				aTime++;
			}
		}

		if (cent[t] >= B && cent[t] < A)
		{
			for (int i = cent[t]; i >= B; i -= B)
			{
				cent[t] -= B;
				bTime++;
			}
		}

		if (cent[t] >= C && cent[t] < B)
		{
			for (int i = cent[t]; i >= C; i -= C)
			{
				cent[t] -= C;
				cTime++;
			}
		}

		if (cent[t] >= D && cent[t] < C)
		{
			for (int i = cent[t]; i >= D; i -= D)
			{
				cent[t] -= D;
				dTime++;
			}
		}

		cout << aTime << " " << bTime << " " << cTime << " " << dTime << endl;
		aTime = 0;
		bTime = 0;
		cTime = 0;
		dTime = 0;
	}

	return 0;
}
