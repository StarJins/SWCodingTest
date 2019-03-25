#include <iostream>

using namespace std;

int N, M;
int dice[6] = { 0,0,0,0,0,0 };
// 전개도에 따른 1,2,3,4,5,6 위치

void diceroll(int Map[][20], int k, int &x, int &y);

int main()
{
	int x, y, k;
	cin >> N >> M >> x >> y >> k;
	int map[20][20] = { 0 };
	int *K = new int[k];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < k; i++)
	{
		cin >> K[i];
	}

	for (int i = 0; i < k; i++)
	{
		diceroll(map, K[i], x, y);
	}
	delete[]K;
	return 0;
}

void diceroll(int Map[][20], int k, int &x, int &y)
{
	int temp;
	switch (k)
	{
	case 1:
		if (y >= M - 1)
		{
			break;
		}
		++y;
		temp = dice[3];
		dice[3] = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[5];
		dice[5] = temp;		
		if (Map[x][y] == 0)				//change dice
		{
			Map[x][y] = dice[5];
		}
		else {
			dice[5] = Map[x][y];
			Map[x][y] = 0;
		}
		cout << dice[0] << endl;
		break;
	case 2:
		if (y <= 0)
		{
			break;
		}
		--y;
		temp = dice[2];
		dice[2] = dice[0];
		dice[0] = dice[3];
		dice[3] = dice[5];
		dice[5] = temp;
		if (Map[x][y] == 0)
		{
			Map[x][y] = dice[5];
		}
		else {
			dice[5] = Map[x][y];
			Map[x][y] = 0;
		}
		cout << dice[0] << endl;
		break;
	case 3:
		if (x <= 0)
		{
			break;
		}
		--x;
		temp = dice[4];
		dice[4] = dice[0];
		dice[0] = dice[1];
		dice[1] = dice[5];
		dice[5] = temp;
		if (Map[x][y] == 0)
		{
			Map[x][y] = dice[5];
		}
		else {
			dice[5] = Map[x][y];
			Map[x][y] = 0;
		}
		cout << dice[0] << endl;
		break;
	case 4:
		if (x >= N - 1)
		{
			break;
		}
		++x;
		temp = dice[1];
		dice[1] = dice[0];
		dice[0] = dice[4];
		dice[4] = dice[5];
		dice[5] = temp;
		if (Map[x][y] == 0)
		{
			Map[x][y] = dice[5];
		}
		else {
			dice[5] = Map[x][y];
			Map[x][y] = 0;
		}
		cout << dice[0] << endl;
		break;
	}
}