#include <iostream>

using namespace std;

char asc(int a, int b, int c,int y, int x)
{
	int T = 2126 * a + 7152 * b + 722 * c;
	if (T >= 0 && T < 510000)
	{
		return '#';
	}
	else if (T >= 510000 && T < 1020000)
	{
		return 'o';
	}
	else if (T >= 1020000 && T < 1530000)
	{
		return '+';
	}
	else if (T >= 1530000 && T < 2040000)
	{
		return '-';
	}
	else {
		return '.';
	}
}

int main()
{
	int arr[400][1200];
	char ascii[400][400];
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][3 * j ];
			cin >> arr[i][3 * j + 1];
			cin >> arr[i][3 * j + 2];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			ascii[i][j] = asc(arr[i][3 * j ], arr[i][3 * j + 1], arr[i][3 * j + 2],i,j);
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << ascii[i][j];
		}
		cout << endl;
	}
	
	system("pause");
	return 0;
}