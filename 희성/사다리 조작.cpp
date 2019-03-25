#include <iostream>

using namespace std;

int result = 4;


bool checkarr(int arr[][10], int sadari[][9], int N, int H)
{
	int x;
	int y;
	for (int i = 0; i < N - 1; i++)		//N-1개가 맞게 도착하면 나머지 하나는 자동으로 확인
	{
		x = i;
		y = 0;
		while (y != H)
		{
			if (x == 0)		//맨 왼쪽에서 사다리 탈 경우
			{
				if (sadari[y][0] == 1)
				{
					x++;
					y++;
				}
				else {
					y++;
				}
			}
			else if (x == N - 1)	//맨 오른쪽에서 사다리 탈 경우
			{
				if (sadari[y][N - 2] == 1)	
				{
					x--;
					y++;
				}
				else {
					y++;
				}
			}
			else {	//그외
				if (sadari[y][x] == 1)	
				{
					x++;
					y++;
				}
				else if (sadari[y][x-1] == 1) {
					x--;
					y++;
				}
				else {
					y++;
				}
			}
		}
		if (x != i)
		{
			return false;
		}
	}
	return true;
}

void recursive(int arr[][10], int sadari[][9], int bc, int N, int H, int I)	//I는 중복 탐색을 방지하기 위해 넣음...
{
	if (bc < 4)
	{
		for (int i = I; i < H; i++)
		{
			for (int j = 0; j < N-1; j++)
			{
				if (j == 0)	//가로줄을 제일 왼쪽에 놓고 싶은 경우
				{
					if (sadari[i][j]!=1 && sadari[i][j + 1] != 1)	
					{
						sadari[i][j] = 1;
						arr[i][j] = 1;
						arr[i][j + 1] = 1;
						if (checkarr(arr, sadari, N, H) == 1)
						{
							if (result > bc)
							{
								result = bc;							
							}
							if (bc == 1)
							{
								break;
							}
						}
						recursive(arr, sadari, bc + 1, N, H, i);
						sadari[i][j] = 0;
						arr[i][j] = 0;
						arr[i][j + 1] = 0;
					
					}
				}
				else if (j == N - 2 && j!=0)
				{
					if (sadari[i][j] != 1 && sadari[i][j - 1] != 1)
					{
						sadari[i][j] = 1;
						arr[i][j] = 1;
						arr[i][j + 1] = 1;
						if (checkarr(arr, sadari, N, H) == 1)
						{
							if (result > bc)
							{
								result = bc;
							}
							if (bc == 1)
							{
								break;
							}
						}
						recursive(arr, sadari, bc + 1, N, H, i);
						sadari[i][j] = 0;
						arr[i][j] = 0;
						arr[i][j + 1] = 0;
					
					}
				}
				else {
					if (sadari[i][j] != 1 && sadari[i][j - 1] != 1 && sadari[i][j + 1] != 1)
					{
						sadari[i][j] = 1;
						arr[i][j] = 1;
						arr[i][j + 1] = 1;
						if (checkarr(arr, sadari, N, H) == 1)
						{
							if (result > bc)
							{
								result = bc;
							}
							if (bc == 1)
							{
								break;
							}
						}
						recursive(arr, sadari, bc + 1, N, H, i);
						sadari[i][j] = 0;
						arr[i][j] = 0;
						arr[i][j + 1] = 0;
					}
				}
				
			}
			if (result == 1)
			{
				break;
			}
		}
	}
}



int main(void)
{
	int N, M, H;	// 세로선 개수, 가로선 개수, 가로축 개수
	int arr[30][10] = { 0 };	//가로선 만나는 점들 위치
	int sadari[30][9] = { 0 };	//가로선 위치
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		sadari[a-1][b-1] = 1;
		arr[a-1][b-1] = 1;
		arr[a-1][b] = 1;
	}
	
	if (checkarr(arr, sadari, N, H) == 1)
	{
		cout << "0" << endl;
	}
	else {
		recursive(arr, sadari, 1, N, H, 0);
		if (result == 4)
		{
			cout << "-1" << endl;
		}
		else {
			cout << result << endl;
		}
	}

	return 0;
}

