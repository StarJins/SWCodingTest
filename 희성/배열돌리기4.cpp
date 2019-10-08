#include <iostream>

using namespace std;

typedef struct rotate{
	int r;
	int c;
	int s;
}Rotate;

int N, M, K;
int arr[51][51];
int replarr[51][51];	//복사된 배열
Rotate Rotatearr[6];	//회전 연산 들어가는곳
int rotatecheck[6] = { 0 };	//연산 했는지 확인, 순서 정함
int arrmin = 987654321;	//배열연산값
int tempval[4][50];	//회전연산때 필요한 임시배열

void cal()
{
	int count;
	for (int i = 1; i <= N; i++)
	{
		count = 0;
		for (int j = 1; j <= M; j++)
		{
			count += replarr[i][j];
		}
		//cout << count << endl;
		if (count < arrmin)
		{
			arrmin = count;
		}
	}

}

void rotating(int rotateval)
{
	int newr, newc, news;	
	newr=Rotatearr[rotateval].r;
	newc=Rotatearr[rotateval].c;
	news=Rotatearr[rotateval].s;
	for (int sval = 1; sval <= news; sval++) //1~s까지
	{
		for (int i = 0; i < 2 * sval; i++)
		{
			tempval[0][i] = replarr[newr - sval][newc - sval + i];
			tempval[1][i] = replarr[newr - sval + i][newc + sval];
			tempval[2][i] = replarr[newr + sval][newc + sval - i];
			tempval[3][i] = replarr[newr + sval - i][newc - sval];	//복사하기
		}

		for (int i = 0; i < 2 * sval; i++)
		{
			replarr[newr - sval][newc - sval + i + 1] = tempval[0][i];
			replarr[newr - sval + i + 1][newc + sval] = tempval[1][i];
			replarr[newr + sval][newc + sval - i - 1] = tempval[2][i];
			replarr[newr + sval - i - 1][newc - sval] = tempval[3][i];	//붙이기
		}
		// r-sval, c-sval ~ r-sval, c+sval-1   =>   r-sval, c-sval+1 ~ r-sval, c+sval : 각 2sval개
		// r-sval, c+sval ~ r+sval-1, c+sval =>   r-sval+1, c+sval ~ r+sval, c+sval
		// r+sval, c+sval ~ r+sval, c-sval+1  => r+sval, c+sval-1 ~ r+sval, c-sval
		// r+sval, c-sval ~ r-sval+1, c-sval => r+sval-1, c-sval ~ r-sval, c-sval	옮기기
	}
}

void DFS(int temp)
{
	if (temp < K)
	{
		for (int i = 0; i < K; i++)	//배열 찾기
		{
			if (rotatecheck[i] == 0)
			{
				rotatecheck[i] = temp+1; //1~6 순서
				DFS(temp + 1);
				rotatecheck[i] = 0;
			}
		}
	}
	else {	//DFS 끝
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				replarr[i][j] = arr[i][j];
			}
		}	//배열 복사하기
		for (int i = 1; i <= K; i++) //연산순서
		{
			for (int j = 0; j < K; j++)
			{
				if (rotatecheck[j] == i)	//1~K까지
				{
					rotating(j);	//회전연산 수행
				}
			}
		}
		cal();	//배열 값 계산해서 업데이트
	}
}

int main(void)
{
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> arr[i][j];
		}
	}	//배열 받기
	

	for (int i = 0; i < K; i++)	
	{
		cin >> Rotatearr[i].r >> Rotatearr[i].c >> Rotatearr[i].s;
	}	//회전 연산 받기

	DFS(0);

	cout << arrmin;
	system("pause");
	return 0;
}