#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    n = 1000 - n;

    array<int, 1000> dp;
    dp.fill(0);
    for (int i = 1; i <= n; ++i)
    {
        int min_val = dp[i - 1] + 1;
        for (auto iter : { 5, 10, 50, 100, 500 })
        {
            if (i < iter)
                break;

            min_val = min(min_val, dp[i - iter] + 1);
        }
        dp[i] = min_val;
    }
    
    cout << dp[n];

    return 0;
}