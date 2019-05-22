#include <iostream>

using namespace std;

int xpos[4] = { 0,1,0,-1 };
int ypos[4] = { -1,0,1,0 };

void spreadcheese(int newarr[][100], int N, int M, int x, int y)
{
	newarr[x][y] = 2;
	if (newarr[x + xpos[0]][y + ypos[0]] == 0)
	{
		spreadcheese(newarr, N, M, x + xpos[0], y + ypos[0]);
	}else if (newarr[x + xpos[0]][y + ypos[0]] == 1)
	{
		newarr[x + xpos[0]][y + ypos[0]] = 3;
	}

	if (newarr[x + xpos[1]][y + ypos[1]] == 0)
	{
		spreadcheese(newarr, N, M, x + xpos[1], y + ypos[1]);
	}
	else if (newarr[x + xpos[1]][y + ypos[1]] == 1)
	{
		newarr[x + xpos[1]][y + ypos[1]] = 3;
	}

	if (newarr[x + xpos[2]][y + ypos[2]] == 0)
	{
		spreadcheese(newarr, N, M, x + xpos[2], y + ypos[2]);
	}
	else if (newarr[x + xpos[2]][y + ypos[2]] == 1)
	{
		newarr[x + xpos[2]][y + ypos[2]] = 3;
	}

	if (newarr[x + xpos[3]][y + ypos[3]] == 0)
	{
		spreadcheese(newarr, N, M, x + xpos[3], y + ypos[3]);
	}
	else if (newarr[x + xpos[3]][y + ypos[3]] == 1)
	{
		newarr[x + xpos[3]][y + ypos[3]] = 3;
	}
}
//2: 방문한 빈 곳, 3: 공기에 접촉된 치즈

void cheese(int arr[][100], int N, int M, int &count)
{
	int newarr[100][100];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			newarr[i][j] = arr[i][j];
		}
	}
	spreadcheese(newarr, N,M, 0, 0);
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (newarr[i][j] == 3)
			{
				arr[i][j] = 0;
				count++;
			}
		}
	}

}


int main()
{
	int N, M;
	int arr[100][100] = { -1 };
	cin >> N >> M;	//N: 세로, M: 가로 arr[N][M]
	int time=0;	//없어지는 시간
	int count = 0;
	int precount=0;	//한시간전 남아있는 치즈조각 수
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
	while (1)
	{
		count = 0;
		cheese(arr, N, M, count);
		if (count == 0)
		{
			break;
		}
		precount = count;
		time++;
	}
	cout << time << endl;
	cout << precount << endl;

	system("pause");
	return 0;
}