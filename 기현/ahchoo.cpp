#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;
pair<int, int> mv[3] = { {1,0}, {0,1}, {1,1} };
int N;
int minimum = INT_MAX;
int xWave[2000];
int yWave[2000];
int dp[2000][2000];

void DFS(int x, int y, int sum) {
	int i;

	if (sum > minimum) {
		return;
	}
	else if (x == N - 1) {
		while (y <= N - 1) {
			if (dp[x][y] == 0) {
				dp[x][y] = abs((xWave[x] - yWave[y]) * (xWave[x] - yWave[y]));
			}
			sum += dp[x][y];
			y++;
			if (sum > minimum) {
				return;
			}
		}
		minimum = min(minimum, sum);
		return;
	}
	else if (y == N - 1) {
		while (x <= N - 1) {
			if (dp[x][y] == 0) {
				dp[x][y] = abs((xWave[x] - yWave[y]) * (xWave[x] - yWave[y]));
			}
			sum += dp[x][y];
			x++;
			if (sum > minimum) {
				return;
			}
		}
		minimum = min(minimum, sum);
		return;
	}
	
	for (i = 0; i < 3; i++) {
		int mvX = x + mv[i].first;
		int mvY = y + mv[i].second;
		if (dp[x][y] == 0) {
			dp[x][y] = abs((xWave[x] - yWave[y]) * (xWave[x] - yWave[y]));
		}
		DFS(mvX, mvY, sum + dp[x][y]);
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

	cout << minimum << endl;

	return 0;
}