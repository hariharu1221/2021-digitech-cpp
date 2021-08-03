#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x, y;
    cin >> x >> y;

    long long p = y * 100 / x;
    if (p >= 99)
    {
        cout << -1;
        return 0;
    }

    /*
    100(y + a) / (x + a) = (p + 1);
    100y + 100a          = (p+ 1)(x + a);
    100y + 100a          = (p + 1)x + (p + 1)a;
    100a                 = (p + 1)x + (p + 1)a - 100y;
    (100 - (p + 1))a     = (p + 1)x - 100y;
    a                    = (p + 1)x - 100y / (99 - p));
    */

    long long f = (p + 1) * x - 100 * y;
    long long e = 99 - p;
    double result = (double)f / e;
    //정답인 a는 실수가 아니라 정수이므로, 조건을 만족하는 a는 cell(a)이다.
    long long answer = ceil(result);

    cout << answer;

    return 0;
}