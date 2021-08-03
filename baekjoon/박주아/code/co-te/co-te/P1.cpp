#include "P1.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char P1::name[256] = "프로그래머스 1 - 완주하지 못한 선수";
void P1::answer()
{
    string answer;
    vector<string> participant = { "marina", "josipa", "nikola", "vinko", "filipa" };
    vector<string> completion = { "josipa", "filipa", "marina", "nikola" };
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for (int i = 0; i < completion.size(); i++)
    {
        if (participant[i] != completion[i])
        {
            cout << participant[i] << endl;
            return;
        }
    }
    cout << participant[participant.size() - 1] << endl;
}