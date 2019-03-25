#include <iostream>

using namespace std;

int result = 4;


bool checkarr(int arr[][10], int sadari[][9], int N, int H)
{
	int x;
	int y;
	for (int i = 0; i < N - 1; i++)		//N-1���� �°� �����ϸ� ������ �ϳ��� �ڵ����� Ȯ��
	{
		x = i;
		y = 0;
		while (y != H)
		{
			if (x == 0)		//�� ���ʿ��� ��ٸ� Ż ���
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
			else if (x == N - 1)	//�� �����ʿ��� ��ٸ� Ż ���
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
			else {	//�׿�
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

void recursive(int arr[][10], int sadari[][9], int bc, int N, int H, int I)	//I�� �ߺ� Ž���� �����ϱ� ���� ����...
{
	if (bc < 4)
	{
		for (int i = I; i < H; i++)
		{
			for (int j = 0; j < N-1; j++)
			{
				if (j == 0)	//�������� ���� ���ʿ� ���� ���� ���
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
	int N, M, H;	// ���μ� ����, ���μ� ����, ������ ����
	int arr[30][10] = { 0 };	//���μ� ������ ���� ��ġ
	int sadari[30][9] = { 0 };	//���μ� ��ġ
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

