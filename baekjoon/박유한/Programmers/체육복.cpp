#include <string>
#include <vector>
#include <array>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {

    array<int, 31> arr;
    arr.fill(1);
    arr[0] = 0;

    for (auto iter : lost)
        arr[iter] = 0;

    for (auto iter : reserve)
        ++arr[iter];

    int lostPeople = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (arr[i] == 0)
        {
            if (arr[i - 1] == 2)
                arr[i - 1] = arr[i] = 1;
            else if (arr[i + 1] == 2)
                arr[i + 1] = arr[i] = 1;
            else
                ++lostPeople;
        }
    }

    return n - lostPeople;
}

#include <iostream>
int main()
{
    cout << solution(5, { 2,4 }, { 1,3,5 }) << endl;
    cout << solution(5, { 2,4 }, { 3 }) << endl;
    cout << solution(3, { 3 }, { 1 }) << endl;
    cout << solution(5, { 4,2 }, { 3,5 }) << endl;
}