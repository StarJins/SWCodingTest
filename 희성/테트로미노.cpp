#include <iostream>

using namespace std;
int tetro[500][500];
int Sum=0;
int FinalSum = 0;
int N, M;

bool posX(int num)
{
	if (num >= N || num<0)
	{
		return false;
	}
	else {
		return true;
	}
}

bool posY(int num)
{
	if (num >= M || num < 0)
	{
		return false;
	}
	else {
		return true;
	}
}

void noFUC(int tetro[][500], int bc, int rec, int x, int y);

void FUC(int tetro[][500], int x, int y);		/*		X
															   XXX     */


int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> tetro[i][j];
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			noFUC(tetro, 0, 0, i, j);
			FUC(tetro, i, j);
		}
	}
	cout << FinalSum << endl;

	system("pause");
	return 0;
}

void noFUC(int tetro[][500], int bc, int rec, int x, int y)		//rec: 이미 거쳐온 지점 안가게 함
{
	if (bc < 4)	//bc가 4개가 될때까지 recursive
	{
		if (posX(x + 1)&&rec!=1)
		{
			Sum += tetro[x][y];
			noFUC(tetro, bc + 1, 2, x + 1, y);
			Sum -= tetro[x][y];
		}
		if (posX(x - 1)&&rec!=2)
		{
			Sum += tetro[x][y];
			noFUC(tetro, bc + 1, 1, x - 1, y);
			Sum -= tetro[x][y];
		}
		if (posY(y + 1)&&rec!=3)
		{
			Sum += tetro[x][y];
			noFUC(tetro, bc + 1, 4, x, y+1);
			Sum -= tetro[x][y];
		}
		if (posY(y - 1)&&rec!=4)
		{
			Sum += tetro[x][y];
			noFUC(tetro, bc + 1, 3, x, y - 1);
			Sum -= tetro[x][y];
		}
	}
	else {
		if (FinalSum < Sum)
		{
			FinalSum = Sum;
		}
	}
}

void FUC(int tetro[][500], int x, int y)
{
	if (posY(y + 2) && posX(x - 1))//ㅓ
	{
		Sum = tetro[x][y] + tetro[x][y + 1] + tetro[x][y + 2] + tetro[x - 1][y + 1];
		if (FinalSum < Sum)
		{
			FinalSum = Sum;
		}
		Sum = 0;
	}
	if (posY(y + 2) && posX(x+1))//ㅏ
	{
		Sum = tetro[x][y] + tetro[x][y + 1] + tetro[x][y + 2] + tetro[x + 1][y + 1];
		if (FinalSum < Sum)
		{
			FinalSum = Sum;
		}
		Sum = 0;
	}
	if (posY(y+1) && posX(x +2))//ㅜ
	{
		Sum = tetro[x][y] + tetro[x + 1][y] + tetro[x + 2][y] + tetro[x + 1][y +1];
		if (FinalSum < Sum)
		{
			FinalSum = Sum;
		}
		Sum = 0;
	}
	if (posY(y -1) && posX(x +2))//ㅗ
	{
		Sum = tetro[x][y] + tetro[x + 1][y] + tetro[x + 2][y] + tetro[x + 1][y -1];
		if (FinalSum < Sum)
		{
			FinalSum = Sum;
		}
		Sum = 0;
	}
}