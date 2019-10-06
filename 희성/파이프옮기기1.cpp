#include <iostream>
#include <queue>

using namespace std;
typedef struct {
	int fx;
	int fy;
	int ix;
	int iy;	//pipe의 좌표들
}pos;
typedef queue<pos> Q;

pos temp;	
Q pipe;

void row(int x, int y)	//가로
{
	temp.fx = x;
	temp.fy = y;
	temp.ix = x;
	temp.iy = y + 1;
	pipe.push(temp);
	//cout << "row" << endl;
}

void col(int x, int y)	//세로
{
	temp.fx = x;
	temp.fy = y;
	temp.ix = x+1;
	temp.iy = y;
	pipe.push(temp);
	//cout << "col" << endl;
}

void diag(int x, int y)	//대각선
{
	temp.fx = x;
	temp.fy = y;
	temp.ix = x+1;
	temp.iy = y + 1;
	pipe.push(temp);
	//cout << "diag" << endl;
}

int main(void)
{
	int N;
	cin >> N;
	int arr[17][17];
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}
	int count = 0;

	pos in;
	pos out;
	in.fx = 1;
	in.fy = 1;
	in.ix = 1;
	in.iy = 2;
	pipe.push(in);

	while (!pipe.empty())
	{
		out = pipe.front();
		pipe.pop();
		//cout << out.fx << out.fy << out.ix << out.iy << endl;
		if (out.ix == N && out.iy == N)
		{
			count++;
		}
		else {
			if (out.fy + 1 == out.iy && out.fx + 1 == out.ix)	//대각선 방향 일 경우
			{
				if (out.iy+1<=N && arr[out.ix][out.iy+1] == 0)
				{
					row(out.ix, out.iy);
				}	//벽 없을시 가로 방향 push
				
				if (out.ix +1<= N && arr[out.ix+1][out.iy] == 0)
				{
					col(out.ix, out.iy);
				}	//벽 없을시 세로방향 push
				
				if (out.iy+1<= N && out.ix + 1 <= N && arr[out.ix][out.iy + 1] == 0 && 
					arr[out.ix + 1][out.iy] == 0 && arr[out.ix + 1][out.iy+1] == 0)
				{
					diag(out.ix, out.iy);
				}	//벽 없을시 대각선 방향 push
			}
			else if (out.fx + 1 == out.ix)	//세로 방향
			{
				if (out.ix + 1 <= N && arr[out.ix + 1][out.iy] == 0)
				{
					col(out.ix, out.iy);
				}	//벽 없을시 세로방향 push
				if (out.iy + 1 <= N && out.ix + 1 <= N && arr[out.ix][out.iy + 1] == 0 &&
					arr[out.ix + 1][out.iy] == 0 && arr[out.ix + 1][out.iy + 1] == 0)
				{
					diag(out.ix, out.iy);
				}	//벽 없을시 대각선 방향 push
			}
			else {	//가로 방향
				if (out.iy + 1 <= N && arr[out.ix][out.iy + 1] == 0)
				{
					row(out.ix, out.iy);
				}	//벽 없을시 가로 방향 push
				if (out.iy + 1 <= N && out.ix + 1 <= N && arr[out.ix][out.iy + 1] == 0 &&
					arr[out.ix + 1][out.iy] == 0 && arr[out.ix + 1][out.iy + 1] == 0)
				{
					diag(out.ix, out.iy);
				}	//벽 없을시 대각선 방향 push
			}
		}
	}

	cout << count;
	
	system("pause");
	return 0;
}


//BFS




