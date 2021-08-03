#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
	char answer = lost.size();

	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());

	for (char l = 0; l < lost.size(); l++)
		for (char r = 0; r < reserve.size(); r++)
			if (reserve[r] == lost[l])
				reserve[r] = -100, lost[l] = -200, --answer;

	for (char l = 0; l < lost.size(); l++)
		for (char r = 0; r < reserve.size(); r++)
			if (reserve[r] == lost[l] - 1 || reserve[r] == lost[l] + 1)
				reserve[r] = -100, lost[l] = -200, --answer;

	return answer;
}

int main()
{
	int N, S, R;
	cin >> N >> S >> R;

	vector<int> lost(S);
	vector<int> reserve(R);

	for (size_t i = 0; i < S; i++)
		cin >> lost[i];

	for (size_t i = 0; i < R; i++)
		cin >> reserve[i];

	cout << solution(N, lost, reserve);

	return 0;
}