#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

int maximum = -pow(2, 31) + 1;

vector <int> equ;
// vector <char> opers;

int op(int front, int oper, int back)
{
	if (oper == 1)
		return front + back;
	else if (oper == 2)
		return front - back;
	else if (oper == 3)
		return front * back;
	else
	{
		cout << "operator error!" << endl;
		return 0;
	}


}

void sol(int idx, int subsol)
{
	if (idx >= equ.size())
	{
		if (subsol > maximum)
		{
			maximum = subsol;
		}
			
		return;
	}

	else if (idx == equ.size() - 1)
	{
		// sol(idx + 1, op(subsol, nums[idx], oper), );
		sol(idx + 1, op(subsol, equ[idx-1], equ[idx]));
	}

	else
	{
		// 괄호 붙이고 간다
		sol(idx + 4, op(subsol, equ[idx-1], op(equ[idx], equ[idx + 1], equ[idx + 2])));

		// 괄호 안 붙이고 간다
		sol(idx + 2, op(subsol, equ[idx - 1], equ[idx]));
	}

	return;

}



int main(void)
{
	

	int n;
	// char t;
	// int subsol = 0;
	int num;
	char tempop;

	cin >> n;

	// 식의 맨 앞에 0+ 를 붙여줌.
	equ.push_back(0);
	equ.push_back(1);

	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			cin >> num;
			equ.push_back(num);
		}
		else
		{
			cin >> tempop;
			if (tempop == '+')
				equ.push_back(1);
			else if (tempop == '-')
				equ.push_back(2);
			else if (tempop == '*')
				equ.push_back(3);
			else
			{
				cout << "operator error!" << endl;
				return 0;
			}
		}

		
	}


	sol(2, 0);

	cout << maximum << endl;

	system("pause");
	return 0;
}