#include <iostream>

using namespace std;
int N, M;
int Ox, Oy = 0;		//O의 x,좌표
int S=11;	//기울인 횟수

void slide(char board[][10], int bc, int Bx, int By, int Rx, int Ry, int k);

int main(void)
{
	cin >> N >> M;
	char board[10][10];
	int Bx, By, Rx, Ry;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			board[i][j] = '0';
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 'B')
			{
				Bx = i;
				By = j;
				break;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 'R')
			{
				Rx = i;
				Ry = j;
				break;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 'O')
			{
				Ox = i;
				Oy = j;
				break;
			}
		}
	}
	slide(board, 1, Bx, By, Rx, Ry, 0);

	if (S == 11)
	{
		cout << -1 << endl;
	}
	else {
		cout << S << endl;
	}

	return 0;
}



void slide(char board[][10], int bc, int Bx, int By, int Rx, int Ry, int k) //bc: recursive한 횟수   k: 같은 방향 제거 up/down/left/right 1/2/3/4
{
	int B_x=0, B_y = 0;
	int R_x=0, R_y = 0;	//B, R를 한 방향으로 움직였을 때 이동한 거리
	/*
	#######Y
	#...RB#
	#.#####
	#.....#
	#####.#
	#O....#
	#######		
	X*/

	if (bc < 11)
	{
		//case up 
		while (board[Bx - B_x - 1][By] == '.')	//B 이동시킬 수 있는 거리
		{
			B_x++;		
		}
		while (board[Rx - R_x - 1][Ry] == '.')	//R 이동시킬 수 있는 거리
		{
			R_x++;
		}

		if (board[Bx - B_x - 1][By] == 'O')	//B가 구멍에 들어가므로 out
		{
			
		}else if(board[Bx - B_x - 1][By] == '#'){
			if (board[Rx - R_x - 1][Ry] == 'O')
			{
				if (S > bc)
				{
					S = bc;	//더 적은 횟수일 경우 저장
				}
			}else if (B_x == 0 && R_x == 0)
				{
					//안움직였으므로 tree 제거
			}
			else {
				if (board[Rx - R_x - 1][Ry] == 'B')		//#-B-R
				{
					R_x = 0;
					while (board[Rx - R_x - 1][Ry] != '#')	//R 이동시킬 수 있는 거리 다시 계산
					{
						R_x++;
					}
					R_x--;
				}
				if (k!=1)
				{
					board[Rx][Ry] = '.';
					board[Bx][By] = '.';
					board[Rx - R_x][Ry] = 'R';
					board[Bx - B_x][By] = 'B';
					slide(board, bc + 1, Bx - B_x, By, Rx - R_x, Ry,1);
					board[Rx - R_x][Ry] = '.';
					board[Bx - B_x][By] = '.';
					board[Rx][Ry] = 'R';
					board[Bx][By] = 'B';
				}
			}
		}
		else {
			if (board[Rx - R_x - 1][Ry] == 'O')	// O-R-B, out.
			{

			}
			else {				//#-R-B
				B_x = 0;
				while (board[Bx - B_x - 1][By] != '#')	//B 이동시킬 수 있는 거리
				{
					B_x++;
				}
				B_x--;	//R 하나 빼기
				if (k != 1)
				{
					board[Rx][Ry] = '.';
					board[Bx][By] = '.';
					board[Rx - R_x][Ry] = 'R';
					board[Bx - B_x][By] = 'B';
					slide(board, bc + 1, Bx - B_x, By, Rx - R_x, Ry, 1);
					board[Rx - R_x][Ry] = '.';
					board[Bx - B_x][By] = '.';
					board[Rx][Ry] = 'R';
					board[Bx][By] = 'B';
				}
			}
		}
		R_x = 0;
		B_x = 0;
		
		//case down 
		while (board[Bx + B_x + 1][By] == '.')	//B 이동시킬 수 있는 거리
		{
			B_x++;
		}
		while (board[Rx + R_x + 1][Ry] == '.')	//R 이동시킬 수 있는 거리
		{
			R_x++;
		}

		if (board[Bx + B_x + 1][By] == 'O')		//B가 구멍에 들어가므로 out
		{

		}
		else if (board[Bx + B_x + 1][By] == '#') {
			if (board[Rx + R_x + 1][Ry] == 'O')
			{
				if (S > bc)
				{
					S = bc;	//더 적은 횟수일 경우 저장
				}
			}
			else if (B_x == 0 && R_x == 0)
			{
				//안움직였으므로 tree 제거
			}
			else {
				if (board[Rx + R_x + 1][Ry] == 'B')		//#-B-R
				{
					R_x = 0;
					while (board[Rx + R_x + 1][Ry] != '#')	//R 이동시킬 수 있는 거리 다시 계산
					{
						R_x++;
					}
					R_x--;
				}
				if (k != 2)
				{
					board[Rx][Ry] = '.';
					board[Bx][By] = '.';
					board[Rx + R_x][Ry] = 'R';
					board[Bx + B_x][By] = 'B';
					slide(board, bc + 1, Bx + B_x, By, Rx + R_x, Ry,2);
					board[Rx + R_x][Ry] = '.';
					board[Bx + B_x][By] = '.';
					board[Rx][Ry] = 'R';
					board[Bx][By] = 'B';
				}
			}
		}
		else {
			if (board[Rx + R_x + 1][Ry] == 'O')	// O-R-B, out.
			{
				R_x = 0;
				B_x = 0;
			}
			else {				//#-R-B
				B_x = 0;
				while (board[Bx + B_x + 1][By] != '#')	//B 이동시킬 수 있는 거리
				{
					B_x++;
				}
				B_x--;	//R 하나 빼기
				if (k != 2)
				{
					board[Rx][Ry] = '.';
					board[Bx][By] = '.';
					board[Rx + R_x][Ry] = 'R';
					board[Bx + B_x][By] = 'B';
					slide(board, bc + 1, Bx + B_x, By, Rx + R_x, Ry,2);
					board[Rx + R_x][Ry] = '.';
					board[Bx + B_x][By] = '.';
					board[Rx][Ry] = 'R';
					board[Bx][By] = 'B';
				}
			}
		}
		R_x = 0;
		B_x = 0;

		//case left
		while (board[Bx][By-B_y-1] == '.')	//B 이동시킬 수 있는 거리
		{
			B_y++;
		}
		while (board[Rx][Ry - R_y - 1] == '.')	//R 이동시킬 수 있는 거리
		{
			R_y++;
		}

		if (board[Bx][By - B_y - 1] == 'O')	//B가 구멍에 들어가므로 out
		{

		}
		else if (board[Bx][By - B_y - 1] == '#') {
			if (board[Rx][Ry - R_y - 1] == 'O')
			{
				if (S > bc)
				{
					S = bc;	//더 적은 횟수일 경우 저장
				}
			}
			else if (B_y == 0 && R_y == 0)
			{
				//안움직였으므로 tree 제거
			}
			else {
				if (board[Rx][Ry - R_y - 1] == 'B')		//#-B-R
				{
					R_y = 0;
					while (board[Rx][Ry - R_y - 1] != '#')	//R 이동시킬 수 있는 거리 다시 계산
					{
						R_y++;
					}
					R_y--;
				}
				if (k != 3)
				{
					board[Rx][Ry] = '.';
					board[Bx][By] = '.';
					board[Rx][Ry - R_y] = 'R';
					board[Bx][By - B_y] = 'B';
					slide(board, bc + 1, Bx, By - B_y, Rx, Ry - R_y,3);
					board[Rx][Ry - R_y] = '.';
					board[Bx][By - B_y] = '.';
					board[Rx][Ry] = 'R';
					board[Bx][By] = 'B';
				}
			}
		}
		else {
			if (board[Rx][Ry-R_y-1] == 'O')	// O-R-B, out.
			{

			}
			else {				//#-R-B
				B_y = 0;
				while (board[Bx][By-B_y-1] != '#')	//B 이동시킬 수 있는 거리
				{
					B_y++;
				}
				B_y--;	//R 하나 빼기
				if (k != 3)
				{
					board[Rx][Ry] = '.';
					board[Bx][By] = '.';
					board[Rx][Ry - R_y] = 'R';
					board[Bx][By - B_y] = 'B';
					slide(board, bc + 1, Bx, By - B_y, Rx, Ry - R_y, 3);
					board[Rx][Ry - R_y] = '.';
					board[Bx][By - B_y] = '.';
					board[Rx][Ry] = 'R';
					board[Bx][By] = 'B';
				}
			}
		}
		R_y = 0;
		B_y = 0;
	}

	//case right
	while (board[Bx][By + B_y + 1] == '.')	//B 이동시킬 수 있는 거리
	{
		B_y++;
	}
	while (board[Rx][Ry + R_y + 1] == '.')	//R 이동시킬 수 있는 거리
	{
		R_y++;
	}

	if (board[Bx][By + B_y + 1] == 'O')	//B가 구멍에 들어가므로 out
	{

	}
	else if (board[Bx][By + B_y + 1] == '#') {
		if (board[Rx][Ry + R_y + 1] == 'O')
		{
			if (S > bc)
			{
				S = bc;	//더 적은 횟수일 경우 저장
			}
		}
		else if (B_y == 0 && R_y == 0)
		{
			//안움직였으므로 tree 제거
		}
		else {
			if (board[Rx][Ry + R_y + 1] == 'B')		//#-B-R
			{
				R_y = 0;
				while (board[Rx][Ry + R_y + 1] != '#')	//R 이동시킬 수 있는 거리 다시 계산
				{
					R_y++;
				}
				R_y--;
			}
			if (k != 4)
			{
				board[Rx][Ry] = '.';
				board[Bx][By] = '.';
				board[Rx][Ry + R_y] = 'R';
				board[Bx][By + B_y] = 'B';
				slide(board, bc + 1, Bx, By + B_y, Rx, Ry + R_y,4);
				board[Rx][Ry + R_y] = '.';
				board[Bx][By + B_y] = '.';
				board[Rx][Ry] = 'R';
				board[Bx][By] = 'B';
			}
		}
	}
	else {
		if (board[Rx][Ry + R_y + 1] == 'O')	// O-R-B, out.
		{

		}
		else {				//#-R-B
			B_y = 0;
			while (board[Bx][By + B_y + 1] != '#')	//B 이동시킬 수 있는 거리
			{
				B_y++;
			}
			B_y--;	//R 하나 빼기
			if (k != 4)
			{
				board[Rx][Ry] = '.';
				board[Bx][By] = '.';
				board[Rx][Ry + R_y] = 'R';
				board[Bx][By + B_y] = 'B';
				slide(board, bc + 1, Bx, By + B_y, Rx, Ry + R_y, 4);
				board[Rx][Ry + R_y] = '.';
				board[Bx][By + B_y] = '.';
				board[Rx][Ry] = 'R';
				board[Bx][By] = 'B';
			}
		}
	}
	R_y = 0;
	B_y = 0;
}
