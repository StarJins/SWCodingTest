#include <iostream>

using namespace std;

void spread(int arr[][50], int R, int C, int cleaner)
{
	int ARCx[2500];
	int ARCy[2500];	//A(r,c) 최대 개수 1000개
	int ARCval[2500];
	int count=0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (arr[i][j] > 4)
			{
				ARCx[count] = i;
				ARCy[count] = j;
				ARCval[count] = arr[i][j];
				arr[i][j] = 0;
				count++;
			}
		}
	}
	
	for (int i = 0; i < count; i++)
	{
		int x = ARCx[i];
		int y = ARCy[i];
		int valadd = ARCval[i] / 5;
		int spr=0;
		//x-1, y
		if (x - 1 >= 0 && arr[x - 1][y] != -1)
		{
			arr[x - 1][y] += valadd;
			spr++;
		}
		//x+1, y
		if (x + 1 < R && arr[x + 1][y] != -1)
		{
			arr[x + 1][y] += valadd;
			spr++;
		}
		//x, y-1
		if (y - 1 >= 0 && arr[x][y - 1] != -1)
		{
			arr[x][y - 1] += valadd;
			spr++;
		}
		//x, y+1
		if (y + 1 < C)
		{
			arr[x][y + 1] += valadd;
			spr++;
		}
		arr[x][y] += (ARCval[i] - valadd * spr);
	}
	

	//위에껑
	for (int i = cleaner - 1; i > 0; i--)
	{
		arr[i][0] = arr[i-1][0];
	}
	for (int i = 0; i<C-1; i++)
	{
		arr[0][i]= arr[0][i+1];
	}
	for (int i = 0; i < cleaner; i++)
	{
		arr[i][C-1] = arr[i+1][C-1];
	}
	for (int i = C - 1; i > 1; i--)
	{
		arr[cleaner][i] = arr[cleaner][i-1];
	}
	arr[cleaner][1] = 0;
	//아래껑
	for (int i = cleaner + 2; i < R - 1; i++)
	{
		arr[i][0] = arr[i+1][0];
	}
	for (int i = 0; i<C-1; i++)
	{
		arr[R - 1][i] = arr[R - 1][i+1];
	}
	for (int i = R-1; i > cleaner + 1; i--)
	{
		arr[i][C - 1] = arr[i-1][C - 1];
	}


	for (int i = C-1; i>1; i--)
	{
		arr[cleaner + 1][i] = arr[cleaner + 1][i-1];
	}
	arr[cleaner + 1][1] = 0;
	
}

/*
for (int i = 0; i < R; i++)
{
	for (int j = 0; j < C; j++)
	{
		cout << arr[i][j] << " ";
	}
	cout << endl;
}
*/

int main()
{
	int R, C, T;	//(r,c), T초
	int arr[50][50];

	cin >> R >> C >> T;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> arr[i][j];
		}
	}
	int cleaner;	//arr[cleaner][0], arr[cleaner+1][0] :공기청정기 위치
	for (int i = 0; i < R; i++)
	{
		if (arr[i][0] == -1)
		{
			cleaner = i;
			break;
		}
	}
	
	for (int i = 1; i <= T; i++)
	{
		spread(arr, R, C, cleaner);
	}
	int result=0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			result += arr[i][j];
		}
	}
	cout << result + 2 << endl;
	//system("pause");
	return 0;
	
}