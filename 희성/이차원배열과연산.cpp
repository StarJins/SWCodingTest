#include <iostream>

using namespace std;

void lineup(int arr[][100], int &row, int &col) {
	int heap[100] = {0};
	int max = 0;
	if (row >= col)		//R ����
	{
		for (int i = 0; i < row; i++)
		{
			int j = 0;
			while (arr[i][j] != 0)
			{
				int k = arr[i][j];
				heap[k - 1]++;
			}
			int t = 0;	//heap�� ����
			for (int i = 0; i < 100; i++)
			{
				if (heap[i] != 0)
				{
					t++;
				}
			}
			j = 0;
			while (t != 0 && j < 50)
			{

				j++;
			}

		}
		col = max;
	}
	else {				//C ����
		for (int i = 0; i < col; i++)
		{

		}
		row = max;
	}

}



int main()
{
	int r, c, k;
	cin >> r >> c >> k;	//rck �Է�
	int arr[100][100];
	for (int i = 0; i < 100; i++)		//�迭 0���� �ʱ�ȭ
	{
		for (int j = 0; j < 100; j++)
		{
			arr[i][j] = 0;
		}
	}
	for (int i = 0; i < 3; i++)		//3*3�迭 �Է�
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}
	}
	int time=0;
	int row = 3;
	int col = 3;
	while (arr[r][c] != k)
	{
		lineup(arr,row,col);
		time++;
	}

	cout << time << endl;
	system("pause");
	return 0;
}