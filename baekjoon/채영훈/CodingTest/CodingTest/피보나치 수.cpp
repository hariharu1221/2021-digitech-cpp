#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;

int main()
{
	int n;

	cin >> n;

	vector<int> dp(46);

	dp[0] = 0;
	dp[1] = 1;

	if (n < 2)
	{
		cout << n << endl;
		return 0;
	}

	for (size_t i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n] << endl;

	return 0;
}