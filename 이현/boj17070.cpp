// boj 17070 파이프 옮기기 1
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
tp 1 : 가로
tp 2 : 세로
tp 3 : 대각선
*/

// pair는 y, x 순으로 넣을 것 (행, 열 순서)

void FF(pair<int, int> b, int tp)
{
	if (b.first == n && b.second == n)
	{
		sol += 1;
		return;
	}

	if (tp == 1) // 원래 가로
	{
		if (pan[b.first][b.second + 1] == 0) // 가로로 이동
		{
			FF(make_pair(b.first, b.second + 1), 1);
		}

		if (pan[b.first][b.second + 1] == 0 && pan[b.first + 1][b.second + 1] == 0 && pan[b.first + 1][b.second] == 0) // 대각선으로 이동
		{
			FF(make_pair(b.first+1, b.second+1), 3);
		}
	}
	else if (tp == 2) // 원래 세로
	{
		if (pan[b.first + 1][b.second] == 0) // 세로로 이동
		{
			FF(make_pair(b.first + 1, b.second), 2);
		}

		if (pan[b.first][b.second + 1] == 0 && pan[b.first + 1][b.second + 1] == 0 && pan[b.first + 1][b.second] == 0) // 대각선으로 이동
		{
			FF(make_pair(b.first + 1, b.second + 1), 3);
		}
	}
	else if (tp == 3)
	{
		if (pan[b.first][b.second + 1] == 0) // 가로로 이동
		{
			FF(make_pair(b.first, b.second + 1), 1);
		}
		if (pan[b.first + 1][b.second] == 0) // 세로로 이동
		{
			FF(make_pair(b.first + 1, b.second), 2);
		}

		if (pan[b.first][b.second + 1] == 0 && pan[b.first + 1][b.second + 1] == 0 && pan[b.first + 1][b.second] == 0) // 대각선으로 이동
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