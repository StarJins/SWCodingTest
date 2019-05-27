#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;
pair<int, int> mv[3] = { {1,1}, {1,0}, {0,1} };//방향
int N;
int minimum = INT_MAX;
int tmp;
int DFScount = 0;
int xWave[2000];
int yWave[2000];
int dp[2000][2000];

void DFS(int x, int y, int sum) {
	int i;
	int cnt = 0;
	int dis;
	int newDis;

	DFScount++;

	if (sum > minimum) {//가지치기 작업
		return;
	}

	if (x == N - 1) {//x 웨이브가 끝에 도달 시 
		while (y <= N - 1) {
			dis = abs((xWave[x] - yWave[y]) * (xWave[x] - yWave[y]));
			if (dp[x][y] == 0) {
				dp[x][y] = sum + dis;
			}
			else {
				if (dp[x][y] <= sum + dis)
					return;
				else
					dp[x][y] = sum + dis;
			}
			sum += dis;
			y++;
		}
		minimum = sum;
		return;
	}

	else if (y == N - 1) {//y 웨이브가 끝에 도달 시 
		while (x <= N - 1) {
			dis = abs((xWave[x] - yWave[y]) * (xWave[x] - yWave[y]));
			if (dp[x][y] == 0) {
				dp[x][y] = sum + dis;
			}
			else {
				if (dp[x][y] <= sum + dis)//가지치기 작업
					return;
				else
					dp[x][y] = sum + dis;
			}
			sum += dis;
			x++;
		}
		minimum = sum;
		return;
	}
	
	for (i = 0; i < 3; i++) {
		dis = abs((xWave[x] - yWave[y]) * (xWave[x] - yWave[y]));
		newDis = sum + dis;

		int mvX = x + mv[i].first;
		int mvY = y + mv[i].second;
		
		if (dp[x][y] == 0) {
			dp[x][y] = newDis;
		}
		else {
			if (dp[x][y] > newDis)
				dp[x][y] = newDis;
			else
				cnt++;
		}
		if (cnt == 3)
			return;

		DFS(mvX, mvY, newDis);
	}
}

int main() {
	int i,j;

	cin >> N;
	
	for (i = 0; i < N; i++)
		cin >> xWave[i];

	for (i = 0; i < N; i++)
		cin >> yWave[i];
	
	DFS(0, 0, 0);

	/*for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cout << dp[i][j] << '\t';
		}
		cout << endl;
	}*/

	//cout << "count: "<< DFScount << endl;
	cout << minimum << endl;

	return 0;
}