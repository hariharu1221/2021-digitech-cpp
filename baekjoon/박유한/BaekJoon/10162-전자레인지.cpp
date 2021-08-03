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

    if (n % 10 != 0)
    {
        cout << -1;
        return 0;
    }

    for (auto iter : { 300, 60, 10})
    {
        cout << n / iter << " ";
        n -= n / iter * iter;
    }

    return 0;
}