#include <iostream>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;
typedef pair<int, int> P;

int N, M, D;
int newD;
int arr[16][16];
int bow[16] = { 0 };
int maxcount = 0;
int c;
stack <P> enemy;
queue <P> save;

bool length(int arrx, int arry, int bowy)	//궁수는 N+1행에 있음
{
	if (N + 1 - arrx + abs(arry - bowy) <= newD)
	{
		return 1;
	}
	else {
		return 0;	//거리되면 1, 안되면 0 반환
	}
}

void DFS(int temp, int x)
{
	if (temp < 3)	//궁수 위치 결정
	{
		for (int i = x; i <= N; i++)
		{
			bow[i] = 1;
			DFS(temp + 1, i + 1);
			bow[i] = 0;
		}
	}
	else {	//시뮬레이션 진행
		c = 0;

		bool flag = 0;
		newD = D;
		int newarr[16][16];
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				newarr[i][j] = arr[i][j];
			}	//배열 복사
		}
		int w = 0;
		while (1)
		{
			P z;
			//cout << w << endl;
			for (int k = 1; k <= M; k++)
			{
				if (bow[k] == 1)	//궁수 찾기, BFS
				{
					save.push(make_pair(N-w,k));
					//cout << N - w << k << endl;
					if (newarr[N - w][k] == 1)
					{
						newarr[N - w][k] = 4;
					}
					else {
						newarr[N - w][k] = 5;	//check
					}
					while (1)
					{
						z=save.front();
						save.pop();
						int xx = z.first;
						int yy = z.second;
						if (length(xx,yy,k)==0)	//거리 초과
						{
							break;
						}
						//cout << newarr[xx][yy] << endl;
						if (newarr[xx][yy] == 4)
						{
							enemy.push(z);
							break;
						}
						if (yy-1>=1 && newarr[xx][yy-1]!=5 && newarr[xx][yy-1]!=4)	//왼쪽 push
						{
							if (newarr[xx][yy - 1] == 0)
							{
								newarr[xx][yy - 1] = 5;	//check
							}
							else {
								newarr[xx][yy - 1] = 4;
							}
							save.push(make_pair(xx, yy - 1));
						}
						if (xx-1>=1 && newarr[xx-1][yy]!=5 && newarr[xx-1][yy]!=4)	//위쪽
						{
							if (newarr[xx - 1][yy] == 0)
							{
								newarr[xx - 1][yy] = 5;	//check
							}
							else {
								newarr[xx - 1][yy] = 4;
							}
							save.push(make_pair(xx - 1, yy));
						}
						if (yy + 1 <= M && newarr[xx][yy + 1] != 5 && newarr[xx][yy+1]!=4)	//오른쪽
						{
							if (newarr[xx][yy + 1] == 0)
							{
								newarr[xx][yy + 1] = 5;	//check
							}
							else {
								newarr[xx][yy + 1] = 4;
							}
							save.push(make_pair(xx, yy + 1));
						}
					}
					for (int i = 1; i <= N; i++)	//check한것들 초기화
					{
						for (int j = 1; j <= M; j++)
						{
							if (newarr[i][j] == 5)
							{
								newarr[i][j] = 0;
							}
							else if (newarr[i][j] == 4)
							{
								newarr[i][j] = 1;
							}
						}
					}
				}
				while (!save.empty())	//필요없는 save pop
				{
					save.pop();
				}

			}
			while (!enemy.empty())	//궁수 공격
			{
				z = enemy.top();
				if (newarr[z.first][z.second] == 1)
				{
					newarr[z.first][z.second] = 0;
					c++;
				}
				enemy.pop();
			}
			/*
			for (int i = 1; i <= N; i++)
			{
				for (int j = 1; j <= M; j++)
				{
					cout << newarr[i][j];
				}
				cout << endl;
			}
			cout << endl;
			*/
			flag = 0;
			for (int i = 1; i <= M; i++)	//못죽인적은 없어짐
			{
				newarr[N - w][i] = 3;
			}
			for (int i = 1; i <= N; i++)	//있는지검사
			{
				for (int j = 1; j <= M; j++)
				{
					if (newarr[i][j] == 1)
					{
						flag = 1;
					}
					if (flag == 1)
					{
						break;
					}
				}
				if (flag == 1)
				{
					break;
				}
			}
			if (flag == 0)	//더이상 적이 없을 경우 break
			{
				break;
			}
			else {
				newD++;
				w++;	//다음 phase
			}
		}
		//cout << c << endl;
		if (c > maxcount)
		{
			maxcount = c;
		}
	}
}

int main(void)
{
	cin >> N >> M >> D;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> arr[i][j];
		}
	}

	DFS(0, 1);

	cout << maxcount;

	system("pause");
	return 0;
}