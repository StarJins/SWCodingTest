#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <math.h>

using namespace std;

vector<vector<int>> pan(11, vector<int>(11, 0));
vector<vector<int>> subsum(11, vector<int>(11, 0));

bool available = false;
int minsol = 30;
int cnt1 = 0;

void DFS(vector<vector<int>> temppan, vector<int> papers, int cnt)
{
	bool bk = false;

	if (cnt > 25 || papers[1] + papers[2] + papers[3] + papers[4] + papers[5] >= minsol)
	{
		return;
	}
		

	if (papers[1] > 5 || papers[2] > 5 || papers[3] > 5 || papers[4] > 5 || papers[5] > 5)
	{
		return;
	}

	if (cnt1 == papers[1] * 1 * 1 + papers[2] * 2 * 2 + papers[3] * 3 * 3 + papers[4] * 4 * 4 + papers[5] * 5 * 5)
	{
		if (minsol > papers[1] + papers[2] + papers[3] + papers[4] + papers[5])
		{
			minsol = papers[1] + papers[2] + papers[3] + papers[4] + papers[5];
		}

		available = true;
		return;
	}

	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)//각각의 모든 칸에 대해서
		{
			if (temppan[i][j] == 1)
			{

				for (int c = 5; c >= 1; c--)
				{
					bool conti = false;

					// 5번 색종이를 붙일 수 있으면 붙이고 넘어가고
					if (i + c - 1 <= 10 && j + c - 1 <= 10)
					{
						for (int ii = i; ii <= c - 1; ii++)
						{
							for (int jj = j; jj <= j + c - 1; jj++)
							{
								if (temppan[ii][jj] == 0)
								{
									conti = true;
									break;
								}
								

							}

							if (conti)
								break;
						}

						if (conti)
							continue;


						if (c * c == subsum[i + c - 1][j + c - 1] - subsum[i + c - 1][j - 1] - subsum[i - 1][j + c - 1] + subsum[i - 1][j - 1])
						{
							for (int a = i; a < i + c; a++)
							{
								for (int b = j; b < j + c; b++)
								{
									temppan[a][b] = 0;
								}
							}

							papers[c] += 1;

							DFS(temppan, papers, cnt+1);

							// 아래는 복원
							papers[c] -= 1;


							for (int a = i; a < i + c; a++)
							{
								for (int b = j; b < j + c; b++)
								{
									temppan[a][b] = 1;
								}
							}
						}
					}
				}

				



				// 3번 색종이를 붙일 수 있으면 붙이고 넘어가고

				// 2번 색종이를 붙일 수 있으면 붙이고 넘어가고

				// 1번 색종이를 붙일 수 있으면 붙이고 넘어가고

				bk = true;
				break;
			}

			


		}

		if (bk)
			break;
	}



}

/*
void DFS(vector<vector<int>> temppan, int one, int two, int three, int four, int five)
{
	if (one > 5 || two > 5 || three > 5 || four > 5 || five > 5)
	{
		return;
	}

	if (cnt1 == one * 1 * 1 + two * 2 * 2 + three * 3 * 3 + four * 4 * 4 + five * 5 * 5)
	{
		if (minsol > one + two + three + four + five)
		{
			minsol = one + two + three + four + five;
		}

		available = true;
		return;
	}

	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)//각각의 모든 칸에 대해서
		{
			if (temppan[i][j] == 1)
			{
				// 5번 색종이를 붙일 수 있으면 붙이고 넘어가고
				if (i + 4 <= 10 && j + 4 <= 10)
				{
					if (25 == subsum[i + 4][j + 4] - subsum[i + 4][j - 1] - subsum[i - 1][j + 4] + subsum[i - 1][j - 1])
					{
						for (int a = i; a < i + 5; a++)
						{
							for (int b = j; b < j + 5; b++)
							{
								temppan[a][b] == 0;
							}
						}

						DFS(temppan, one, two, three, four, five + 1);

						for (int a = i; a < i + 5; a++)
						{
							for (int b = j; b < j + 5; b++)
							{
								temppan[a][b] == 1;
							}
						}
					}
				}

				

				// 3번 색종이를 붙일 수 있으면 붙이고 넘어가고

				// 2번 색종이를 붙일 수 있으면 붙이고 넘어가고

				// 1번 색종이를 붙일 수 있으면 붙이고 넘어가고
			}
			

		}
	}



}
*/
int main(void)
{
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			cin >> pan[i][j];

			if (pan[i][j] == 1)
				cnt1 += 1;

			subsum[i][j] = subsum[i][j - 1] + subsum[i - 1][j] - subsum[i-1][j-1] + pan[i][j];

			
		}
	}

	// cout << endl << cnt1 << endl;

	/*

	
	cout << endl << endl;

	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			cout << pan[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl << endl;

	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			cout << subsum[i][j] << ' ';
		}
		cout << endl;
	}
	*/

	vector<int> ps = { 0,0,0,0,0,0 };

	DFS(pan, ps, 0);
	if(available)
		cout << minsol << endl;
	else
		cout << -1 << endl;
	system("pause");
	return 0;
}