#include "Main.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "-1 : ����" << endl;
	cout << "-2 : ���� ����Ʈ" << endl;

	while (1) {
		cout << "�Է� : ";
		int n;	cin >> n;
		switch (n)
		{
		case -1:
			return 0;
		case -2:
			Main::QuestList();
			break;
		case 1:
			P1::answer();
			break;
		case 2747:
			B2747::answer();
			break;
		case 2750:
			B2750::answer();
			break;
		case 2751:
			B2751::answer();
			break;
		case 19939:
			B19939::answer();
			break;
		}
	}

	return 0;
}

void Main::QuestList()
{
	cout << P1::name << endl;
	cout << B2747::name << endl;
	cout << B2750::name << endl;
	cout << B2751::name << endl;
	cout << B19939::name << endl;
}