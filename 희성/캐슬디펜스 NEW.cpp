#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

typedef pair<int, int> P;
queue <P> enemyattack;	//BFS�� �ʿ���

int N, M, D;
int arr[16][16] = { 0 };
int bow[16];
int maxcount = 0;	//�ִ�
int count1;	//(�ӽ�)������ �� �� 
P enemy[3];	//�� ��ġ ����

bool length(int arrx, int arry, int bowy, int ptime)	//�ü��� N+1�࿡ ����
{
	if (N + 1 - arrx + abs(arry - bowy) <= D+ptime)
	{
		return 1;
	}
	else {
		return 0;	//�Ÿ��Ǹ� 1, �ȵǸ� 0 ��ȯ
	}
}

void BFS(int newmap[][16], int k, int ptime)	//k: �ü� ��ġ
{
	P temp2;
	enemyattack.push(make_pair(N-ptime, k));

	if (newmap[N - ptime][k] == 1) //��ġ�� ����ְ� �ٷ� Ż��
	{
		for (int i = 0; i < 3; i++)
		{
			if (enemy[i].first == 0)	//�� ��ġ ����ֱ�
			{
				enemy[i].first = N - ptime;
				enemy[i].second = k;
				break;
			}
		}
	}
	else {	//ù ��ġ 0�� ��� ã�ƾߵ�
		newmap[N - ptime][k] = 2;	//0->2, 1->3���� ��ȯ
		while (1)
		{
			temp2 = enemyattack.front();
			enemyattack.pop();
			int posx = temp2.first;
			int posy = temp2.second;

			if (length(posx, posy, k, ptime) == 0)	//�Ÿ� ������ �������� ���� ���
			{
				break;	//�ٷ� Ż��
			}
			if (newmap[posx][posy] == 3) //�� ã���� ���
			{
				for (int i = 0; i < 3; i++)
				{
					if (enemy[i].first == 0)	//�� ��ġ ����ֱ�
					{
						enemy[i].first = posx;
						enemy[i].second = posy;
						break;
					}
				}
				break;
			}
			
			if (posy - 1 >= 1 && newmap[posx][posy-1]<=1) //���� Ž�� ���� ��.
			{
				if (newmap[posx][posy - 1] == 1)
				{
					newmap[posx][posy - 1] = 3;	//�湮ó����
				}
				else {
					newmap[posx][posy - 1] = 2;
				}
				enemyattack.push(make_pair(posx, posy-1));
			}

			if (posx - 1 >= 1 && newmap[posx-1][posy] <= 1) //���� Ž�� ���� ��.
			{
				if (newmap[posx-1][posy] == 1)
				{
					newmap[posx-1][posy] = 3;	//�湮ó����
				}
				else {
					newmap[posx-1][posy] = 2;
				}
				enemyattack.push(make_pair(posx-1, posy));
			}

			if (posy + 1 <=M && newmap[posx][posy+1] <= 1) //������ Ž�� ���� ��.
			{
				if (newmap[posx][posy+1] == 1)
				{
					newmap[posx][posy+1] = 3;	//�湮ó����
				}
				else {
					newmap[posx][posy+1] = 2;
				}
				enemyattack.push(make_pair(posx, posy+1));
			}
		}
	}

	for (int i = 1; i <= N; i++)	//�迭 ������� ������
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

	while (!enemyattack.empty()) //queue ����
	{
		enemyattack.pop();
	}

}

void attack(int newmap[][16])	//�ü� ����
{
	int ptime = 0;	//~�̸�ŭ �ð��� ����
	while (1)
	{
		for (int i = 0; i < 3; i++)	//����ġ �ʱ�ȭ
		{
			enemy[i].first = 0;
			enemy[i].second = 0;
		}

		for (int k = 1; k <= M; k++)	//�ü� ã��
		{
			if (bow[k] == 1)  //�ü� �������
			{
				BFS(newmap, k, ptime);	//BFS�� ������
			}
		}

		for (int i = 0; i < 3; i++)	//�ü� ����
		{
			if (newmap[enemy[i].first][enemy[i].second] == 1) //���� ���� ���
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
		for (int i = 1; i <= M; i++) //�� �̵�
		{
			newmap[N-ptime][i] = 0;
		}

		bool flag = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (newmap[i][j] == 1)	//���� ���� �������
				{
					flag = 1;
					break;
				}
			}
			if (flag == 1)	//�ٽ� whlie���� ����
			{
				break;
			}
		}
		if (flag == 0)	//���� ��� ������ ���
		{
			break;	//while���� �������´�
		}
		ptime++;	//���� ����
	}
}

void findbow(int temp, int x)	//DFS
{
	if (temp < 3)	//�ü� ��ġ ����
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
		for (int i = 1; i <= N; i++)	//�迭 ����
		{
			for (int j = 1; j <= M; j++)
			{
				newmap[i][j] = arr[i][j];
			}
		}
		count1 = 0;	//count �ʱ�ȭ

		attack(newmap);	//�ùķ��̼� ������

		if (count1 > maxcount)	//count1�� �� Ŭ��� maxcount �ٲٱ�
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