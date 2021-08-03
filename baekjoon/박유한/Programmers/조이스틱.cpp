#include <string>
#include <vector>

using namespace std;

int alphabetCount(char c)
{
    if (c < 'N')
        return c - 'A';
    return 'Z' + 1 - c;
}

int minMoveCount(string str)
{
    int min = str.size();
    //정면으로만 이동시 최소 숫자
    while (str[--min] == 'A' && min > 0);

    for (int i = 0; i < min / 2; ++i)
    {
        if ((i != 0 && str[i] == 'A') || str[i + 1] != 'A') continue;

        int count = i * 2;
        int nextCharIdx = str.find_first_not_of('A', i + 1);
        count += str.size() - nextCharIdx;

        if (count < min)
            min = count;
    }

    return min;
}

int solution(string name) {
    int result = minMoveCount(name);
    for (auto iter : name)
        result += alphabetCount(iter);

    return result;
}

#include <iostream>

int main()
{
    cout << solution("JEROEN") << endl;
    cout << solution("JAN") << endl;

    return 0;
}