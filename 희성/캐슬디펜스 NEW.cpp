#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

typedef pair<int, int> P;
queue <P> enemyattack;	//BFS때 필요함

int N, M, D;
int arr[16][16] = { 0 };
int bow[16];
int maxcount = 0;	//최대
int count1;	//(임시)제거한 적 수 
P enemy[3];	//적 위치 저장

bool length(int arrx, int arry, int bowy, int ptime)	//궁수는 N+1행에 있음
{
	if (N + 1 - arrx + abs(arry - bowy) <= D+ptime)
	{
		return 1;
	}
	else {
		return 0;	//거리되면 1, 안되면 0 반환
	}
}

void BFS(int newmap[][16], int k, int ptime)	//k: 궁수 위치
{
	P temp2;
	enemyattack.push(make_pair(N-ptime, k));

	if (newmap[N - ptime][k] == 1) //위치에 집어넣고 바로 탈출
	{
		for (int i = 0; i < 3; i++)
		{
			if (enemy[i].first == 0)	//적 위치 집어넣기
			{
				enemy[i].first = N - ptime;
				enemy[i].second = k;
				break;
			}
		}
	}
	else {	//첫 위치 0일 경우 찾아야됨
		newmap[N - ptime][k] = 2;	//0->2, 1->3으로 변환
		while (1)
		{
			temp2 = enemyattack.front();
			enemyattack.pop();
			int posx = temp2.first;
			int posy = temp2.second;

			if (length(posx, posy, k, ptime) == 0)	//거리 조건을 만족하지 않을 경우
			{
				break;	//바로 탈출
			}
			if (newmap[posx][posy] == 3) //적 찾았을 경우
			{
				for (int i = 0; i < 3; i++)
				{
					if (enemy[i].first == 0)	//적 위치 집어넣기
					{
						enemy[i].first = posx;
						enemy[i].second = posy;
						break;
					}
				}
				break;
			}
			
			if (posy - 1 >= 1 && newmap[posx][posy-1]<=1) //왼쪽 탐색 안한 곳.
			{
				if (newmap[posx][posy - 1] == 1)
				{
					newmap[posx][posy - 1] = 3;	//방문처리들
				}
				else {
					newmap[posx][posy - 1] = 2;
				}
				enemyattack.push(make_pair(posx, posy-1));
			}

			if (posx - 1 >= 1 && newmap[posx-1][posy] <= 1) //위쪽 탐색 안한 곳.
			{
				if (newmap[posx-1][posy] == 1)
				{
					newmap[posx-1][posy] = 3;	//방문처리들
				}
				else {
					newmap[posx-1][posy] = 2;
				}
				enemyattack.push(make_pair(posx-1, posy));
			}

			if (posy + 1 <=M && newmap[posx][posy+1] <= 1) //오른쪽 탐색 안한 곳.
			{
				if (newmap[posx][posy+1] == 1)
				{
					newmap[posx][posy+1] = 3;	//방문처리들
				}
				else {
					newmap[posx][posy+1] = 2;
				}
				enemyattack.push(make_pair(posx, posy+1));
			}
		}
	}

	for (int i = 1; i <= N; i++)	//배열 원래대로 돌리기
	{
		for (int j = 1; j <= M; j++)
		{
			if (newmap[i][j] == 3)
			{
				newmap[i][j] = 1;
			}
			else if (newmap[i][j] == 2)
			{
				newmap[i][j] = 0;
			}
		}
	}

	while (!enemyattack.empty()) //queue 비우기
	{
		enemyattack.pop();
	}

}

void attack(int newmap[][16])	//궁수 공격
{
	int ptime = 0;	//~이만큼 시간이 지남
	while (1)
	{
		for (int i = 0; i < 3; i++)	//적위치 초기화
		{
			enemy[i].first = 0;
			enemy[i].second = 0;
		}

		for (int k = 1; k <= M; k++)	//궁수 찾기
		{
			if (bow[k] == 1)  //궁수 있을경우
			{
				BFS(newmap, k, ptime);	//BFS를 돌린다
			}
		}

		for (int i = 0; i < 3; i++)	//궁수 공격
		{
			if (newmap[enemy[i].first][enemy[i].second] == 1) //적이 있을 경우
			{
				newmap[enemy[i].first][enemy[i].second] = 0;
				count1++;
			}
		}
		/*
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				cout << newmap[i][j];
			}
			cout << endl;
		}
		cout << endl;
		*/
		for (int i = 1; i <= M; i++) //적 이동
		{
			newmap[N-ptime][i] = 0;
		}

		bool flag = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (newmap[i][j] == 1)	//적이 남아 있을경우
				{
					flag = 1;
					break;
				}
			}
			if (flag == 1)	//다시 whlie문을 돈다
			{
				break;
			}
		}
		if (flag == 0)	//적을 모두 제거한 경우
		{
			break;	//while문을 빠져나온다
		}
		ptime++;	//다음 공격
	}
}

void findbow(int temp, int x)	//DFS
{
	if (temp < 3)	//궁수 위치 결정
	{
		for (int i = x; i <= M; i++)
		{
			bow[i] = 1;
			findbow(temp + 1, i + 1);
			bow[i] = 0;
		}
	}
	else {
		int newmap[16][16];
		for (int i = 1; i <= N; i++)	//배열 복사
		{
			for (int j = 1; j <= M; j++)
			{
				newmap[i][j] = arr[i][j];
			}
		}
		count1 = 0;	//count 초기화

		attack(newmap);	//시뮬레이션 돌리기

		if (count1 > maxcount)	//count1이 더 클경우 maxcount 바꾸기
		{
			maxcount = count1;
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

	findbow(0, 1);

	cout << maxcount;

	system("pause");
	return 0;
}