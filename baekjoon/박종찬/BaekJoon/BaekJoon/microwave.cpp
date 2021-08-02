#include <iostream>

using namespace std;

int main()
{
	int time;
	const int A = 300;
	const int B = 60;
	const int C = 10;

	int aTime = 0;
	int bTime = 0;
	int cTime = 0;

	cin >> time;

	if (time >= A)
	{
		for (int i = time; i >= A; i -= A)
		{
			time -= A;
			aTime++;
		}
	}

	if (time >= B && time < A)
	{
		for (int i = time; i >= B; i -= B)
		{
			time -= B;
			bTime++;
		}
	}

	if (time >= C && time < B)
	{
		for (int i = time; i >= C; i -= C)
		{
			time -= C;
			cTime++;
		}
	}
	if (time == 0)
	{
		cout << aTime << " " << bTime << " " << cTime;
	}
	else
	{
		cout << -1;
	}

	return 0;
}
