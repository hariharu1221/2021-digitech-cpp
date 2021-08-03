#include <iostream>
#include <array>
#include <algorithm>
#include <string>

using namespace std;

array<string, 50> table;

constexpr char wb[] = "WB";

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        cin >> table[i];

    int result = n * m;
    for (int i = 0; i <= n - 8; ++i)
    {
        for (int j = 0; j <= m - 8; ++j)
        {
            int now_val = 0;
            for (int k = 0; k < 8; ++k)
            {
                for (int l = 0; l < 8; ++l)
                {
                    if (table[i + k][j + l] == wb[(k + l) % 2])
                        ++now_val;
                }
            }

            if (now_val > 32)
                now_val = 64 - now_val;

            result = min(result, now_val);
        }
    }

    cout << result;

    return 0;
}