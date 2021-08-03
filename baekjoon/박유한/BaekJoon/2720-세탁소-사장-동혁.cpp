#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;
        for (auto iter : { 25, 10, 5, 1 })
        {
            cout << n / iter << " ";
            n -= n / iter * iter;
        }
        cout << "\n";
    }

    return 0;
}