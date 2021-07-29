#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace::std;

void Change(int* n1, int* n2);

int main()
{
#pragma region 시간초과

	//vector<int> v;
	//vector<int>::iterator it = v.begin();
	//int count = 0;
	//int num;

	//cin >> count;
	//for (int i = 0; i < count; i++)
	//{
	//	cin >> num;

	//	if (v.size() > 0)
	//	{
	//		for (int j = 0; j < v.size(); j++)
	//		{
	//			if (num < v[j])
	//			{
	//				it = v.insert(it + j, num);
	//				break;
	//			}

	//			if (num == v[j])
	//			{
	//				break;
	//			}

	//			else if (j == v.size() - 1)
	//			{
	//				it = v.insert(it, num);
	//			}
	//		}
	//	}

	//	else
	//	{
	//		it = v.insert(it, num);
	//	}

	//	it = v.begin();
	//}

	//for (int i = 0; i < v.size(); i++)
	//{
	//	cout << v[i] << endl;
	//}

	//return 0;
#pragma endregion

	int count = 0;
	int num;

	cin >> num;

	vector<int> v(num, 0);

	for (int i = 0; i < num; i++)
	{
		cin >> v[i];
	}

	int temp;

	for (int i = 0; i < v.size(); i++)
	{
		temp = v[i];

		for (int j = i; j < v.size(); j++)
		{
			if (temp < v[j])
			{
				Change(&v[i], &v[j]);
			}
		}
	}

	vector<int>::iterator uit = unique(v.begin(), v.end());
	v.erase(uit, v.end());

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	return 0;
}

void Change(int* n1, int* n2)
{
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}
