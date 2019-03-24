#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int width(int **arr, int num, int L, int N);
int height(int **arr, int num, int L, int N);


int main(void)
{
	int **saro;
	int N;
	int L;
	int i, j;
	int roadnum=0;
	scanf("%d %d", &N, &L);
	saro = (int**)malloc(sizeof(int*)*N);
	for (i = 0; i < N; i++)
	{
		*(saro + i) = (int*)malloc(sizeof(int)*N);
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%d", &saro[i][j]);
		}
	}
	for (i = 0; i < N; i++)
	{
		roadnum = roadnum + width(saro, i, L, N);
		roadnum = roadnum + height(saro, i, L, N);
	}
	printf("%d", roadnum);

	system("pause");
	free(saro);
	
	return 0;
}

int width(int **arr, int num, int L, int N)
{
	int *temp;
	int i=1;
	int j;
	temp = (int*)malloc(sizeof(int)*N);
	for (j = 0; j < N; j++)
	{
		temp[j] = 0;
	}
	for (i = 1; i < N; i++)
	{
		if (arr[num][i-1] != arr[num][i])
		{
			break;
		}
	}
	if (i == N)
	{
		return 1;
	}
	else {
		if (i < L)
		{
			if (arr[num][i - 1] < arr[num][i])
			{
				return 0;
			}
		}
	}
	
	i = 1;
	while (arr[num][N-i] == arr[num][N-i-1] && i >0)
	{
		i++;
	}
	if (i < L)
	{
		if (arr[num][N - i] < arr[num][N - i - 1])
		{
			return 0;
		}
	}

	for (i = 1; i < N; i++)
	{
		if (abs(arr[num][i - 1] - arr[num][i]) > 1)
		{
			return 0;
		}
		else if(abs(arr[num][i - 1] - arr[num][i]) == 1)
			
		{
			if (arr[num][i - 1] < arr[num][i])
			{
				j = 0;
				while (j < L&& i - 1 - j>0)
				{
					temp[i - 1 - j]++;
					j++;
				}
			}
			else {
				j = 0;
				while (j < L&& i+j<N)
				{
					temp[i+j]++;
					j++;
				}
			}
		}
	}
	for (i = 0; i < N; i++)
	{
		if (temp[i] > 1)
		{
			return 0;
		}
	}
	free(temp);
	return 1;
}

int height(int **arr, int num, int L, int N)
{
	int *temp;
	int i = 1;
	int j;
	temp = (int*)malloc(sizeof(int)*N);
	for (j = 0; j < N; j++)
	{
		temp[j] = 0;
	}
	for (i = 1; i < N; i++)
	{
		if (arr[i - 1][num] != arr[i][num])
		{
			break;
		}
	}
	if (i == N)
	{
		return 1;
	}
	else {
		if (i < L)
		{
			if (arr[i-1][num] < arr[i][num])
			{
				return 0;
			}
		}
	}

	i = 1;
	while (arr[N-i][num] == arr[N-i-1][num] && i > 0)
	{
		i++;
	}
	if (i < L)
	{
		if (arr[N-i][num] < arr[N-i-1][num])
		{
			return 0;
		}
	}

	for (i = 1; i < N; i++)
	{
		if (abs(arr[i-1][num] - arr[i][num]) > 1)
		{
			return 0;
		}
		else if (abs(arr[i-1][num] - arr[i][num]) == 1)

		{
			if (arr[i-1][num] < arr[i][num])
			{
				j = 0;
				while (j < L&& i - 1 - j>0)
				{
					temp[i - 1 - j]++;
					j++;
				}
			}
			else {
				j = 0;
				while (j < L&& i + j < N)
				{
					temp[i + j]++;
					j++;
				}
			}
		}
	}
	for (i = 0; i < N; i++)
	{
		if (temp[i] > 1)
		{
			return 0;
		}
	}
	free(temp);
	return 1;
}










/*
int stack = 1;
int temp = -1;
int t;
for (t = 1; t < N; t++)
{
	if (arr[t][num] == arr[t - 1][num])
	{
		stack++;
	}
	else {
		if (abs(arr[t][num] - arr[t][num - 1]) == 1)
		{
			if (stack < L)
			{
				if (temp == -1)
				{
					temp = 0;
				}
				else {
					return 0;
				}
			}
			else {
				stack = 1;
			}
		}
		else {
			return 0;
		}
	}
}
return 1;
*/