#include <iostream>

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>

// pair 사용 위해서
#include <utility>
using namespace std;

int enemynum = 0;
int maxsol = 0;
int n, m, d;


vector< vector<int>> pan;
vector < vector<int>> archercases;

int distance(pair<int, int> enemy, pair <int, int> archer) // y, x 순서
{
	return (int)abs(enemy.first - archer.first) + (int)abs(enemy.second - archer.second);
}

void decidearchers(int idx, int howmanyppl, vector<int> archercase)
{
	if (howmanyppl == 3)
	{
		archercases.push_back(archercase);
		return;
	}

	if (idx >= m)
	{
		return;
	}
	// 추가 안하고 가기
	decidearchers(idx + 1, howmanyppl, archercase);

	
	// 추가하고 가기
	archercase.push_back(idx);
	decidearchers(idx + 1, howmanyppl + 1, archercase);
	
	
}

void simulation(vector<int> archercase)
{
	// 각각의 적에 대해서 왼쪽에서부터 첫번째 궁수, 두번째 궁수, 세번째 궁수와의 거리와 적의 좌표를 저장합니다.
	// one[[적과 첫번째 궁수와의 거리, 해당 적의 x좌표, 해당 적의 y좌표], [그 다음 적과 첫번째 궁수와의 거리, 해당 적의 x좌표, 해당 적의 y좌표], ... , ]
	vector<vector<int>> one;
	vector<vector<int>> two;
	vector<vector<int>> three;
	int candisol = 0;


	for (int t = 1; t <= n ; t++)
	{
		for (int i = 0; i <= n - t ; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (pan[i][j] == 1)
				{
					// vector<int> tq;
					// tq.pu
					one.push_back(vector<int> ({distance(make_pair(i, j), make_pair(n, archercase[0])), j, i}));
					two.push_back(vector<int>({ distance(make_pair(i, j), make_pair(n, archercase[1])), j, i }));
					three.push_back(vector<int>({ distance(make_pair(i, j), make_pair(n, archercase[2])), j, i }));

				}
			}
		}

		if (!(one.size() && two.size() && three.size()))
		{
			/*
			if (maxsol < candisol)
			{
				maxsol = candisol;
			}

			return;
			*/
			continue;
		}


		sort(one.begin(), one.end());
		sort(two.begin(), two.end());
		sort(three.begin(), three.end());

		

		if (one[0][0] < d + t)
		{
			if (pan[one[0][2]][one[0][1]] < 0)
			{

			}
			else
			{
				pan[one[0][2]][one[0][1]] = -1 * t;
				candisol += 1;
			}
			
		}
		if (two[0][0] < d + t)
		{
			if (pan[two[0][2]][two[0][1]] < 0);
			else
			{
				pan[two[0][2]][two[0][1]] = -1 * t;
				candisol += 1;
			}
			
		}
		if (three[0][0] < d + t)
		{
			if (pan[three[0][2]][three[0][1]] < 0);
			else
			{
				pan[three[0][2]][three[0][1]] = -1 * t;
				candisol += 1;
			}
			
		}

		one.clear();
		two.clear();
		three.clear();

		if (candisol == enemynum)
		{
			maxsol = candisol;
			return;
		}

		/*
		for (int h = 0; h < m; h++)
		{
			if (pan[n - t][h] == 1)
			{
				if (maxsol < candisol)
				{
					maxsol = candisol;
				}


				return;
			}
		}
		*/
		


	}

	if (maxsol < candisol)
	{
		maxsol = candisol;
	}

	return;
}



int main(void)
{
	// pair<int, int> enemy;
	// pair<int, int> archer;
	cin >> n >> m >> d;

	// vector<vector<int>> pan(n + 1, vector<int>(m, 0));

	for (int i = 0; i < n + 1; i++)
	{
		// vector <int> t(m, 0);
		pan.push_back(vector<int>(m,0));
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int tt;
			cin >> tt;
			// 
			// cin >> pan[i][j];
			if (tt == 1)
			{
				pan[i][j] = tt;
				enemynum += 1;
			}
		}
	}

	
	vector<int> temp;
	decidearchers(0, 0, temp);

	for (int i = 0; i < archercases.size(); i++)
	{

		//초기화

		for (int a = 0; a < n; a++)
		{
			for (int b = 0; b < m; b++)
			{
				if (pan[a][b] != 0)
					pan[a][b] = 1;
			}
		}




		for (int j = 0; j < m; j++)
		{
			pan[n][j] = 0; // 궁수 라인 초기화
		}

		pan[n][archercases[i][0]] = 1;
		pan[n][archercases[i][1]] = 1;
		pan[n][archercases[i][2]] = 1;
		// 궁수 세 명 세팅

		// archernum = 3;

		simulation(archercases[i]);

	}


	cout << maxsol << endl;

	/*
	for (int i = 0; i < archercases.size(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << archercases[i][j] << ' ';
		}
		cout << endl;
	}
	*/
	system("pause");
	return 0;
}