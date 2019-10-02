// boj 17070 ������ �ű�� 1
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;
int n;
vector <vector<int>> pan(18, vector<int>(18, 1));

int sol = 0;

/*
tp 1 : ����
tp 2 : ����
tp 3 : �밢��
*/

// pair�� y, x ������ ���� �� (��, �� ����)

void FF(pair<int, int> b, int tp)
{
	if (b.first == n && b.second == n)
	{
		sol += 1;
		return;
	}

	if (tp == 1) // ���� ����
	{
		if (pan[b.first][b.second + 1] == 0) // ���η� �̵�
		{
			FF(make_pair(b.first, b.second + 1), 1);
		}

		if (pan[b.first][b.second + 1] == 0 && pan[b.first + 1][b.second + 1] == 0 && pan[b.first + 1][b.second] == 0) // �밢������ �̵�
		{
			FF(make_pair(b.first+1, b.second+1), 3);
		}
	}
	else if (tp == 2) // ���� ����
	{
		if (pan[b.first + 1][b.second] == 0) // ���η� �̵�
		{
			FF(make_pair(b.first + 1, b.second), 2);
		}

		if (pan[b.first][b.second + 1] == 0 && pan[b.first + 1][b.second + 1] == 0 && pan[b.first + 1][b.second] == 0) // �밢������ �̵�
		{
			FF(make_pair(b.first + 1, b.second + 1), 3);
		}
	}
	else if (tp == 3)
	{
		if (pan[b.first][b.second + 1] == 0) // ���η� �̵�
		{
			FF(make_pair(b.first, b.second + 1), 1);
		}
		if (pan[b.first + 1][b.second] == 0) // ���η� �̵�
		{
			FF(make_pair(b.first + 1, b.second), 2);
		}

		if (pan[b.first][b.second + 1] == 0 && pan[b.first + 1][b.second + 1] == 0 && pan[b.first + 1][b.second] == 0) // �밢������ �̵�
		{
			FF(make_pair(b.first + 1, b.second + 1), 3);
		}

	}
	else
	{
		cout << "ERROR!" << endl;
		return;
	}
}


int main(void)
{
	cin >> n;

	// pan.push_back()
	/*
	for (int i = 0; i < n ; i++)
	{
		vector<int> temprow(n+2);
		pan.push_back(temprow);
	}
	*/
	int t;



	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> t;
			pan[i+1][j+1] = t;
		}
	}


	//pair <int, int> ia = make_pair(1, 1);
	pair <int, int> ib = make_pair(1, 2);

	FF(ib, 1);

	cout << sol << endl;

	system("pause");
	return 0;
}