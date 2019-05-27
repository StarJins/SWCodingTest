#include <iostream>
#include <algorithm>
using namespace std;

int N;
int xWave[2000];
int yWave[2000];
int dp[2000][2000];


void DFS(int k) {
	int i;
	int a1, a2, a3;
	int b1, b2, b3;
	int dis;
	
	for (i = k; i < N; i++) {
		dis = abs((xWave[i] - yWave[k]) * (xWave[i] - yWave[k]));
		a1 = dp[i-1][k-1] + dis;
		a2 = dp[i][k - 1] + dis;
		a3 = dp[i - 1][k] + dis;
		dp[i][k] = min((min(a1, a2)), a3);

		if (i != k) {
			dis = abs((xWave[k] - yWave[i]) * (xWave[k] - yWave[i]));
			b1 = dp[k - 1][i - 1] + dis;
			b2 = dp[k][i - 1] + dis;
			b3 = dp[k - 1][i] + dis;
			dp[k][i] = min((min(b1, b2)), b3);
		}
	}

}

int main() {
	int i, j;

	cin >> N;

	for (i = 0; i < N; i++)
		cin >> xWave[i];

	for (i = 0; i < N; i++)
		cin >> yWave[i];

	dp[0][0] = abs((xWave[0] - yWave[0]) * (xWave[0] - yWave[0]));

	if (N != 1) {
		for (i = 1; i < N; i++) {
			dp[i][0] = dp[i - 1][0] + abs((xWave[i] - yWave[0]) * (xWave[i] - yWave[0]));
			dp[0][i] = dp[0][i - 1] + abs((xWave[0] - yWave[i]) * (xWave[0] - yWave[i]));
		}
		for (i = 1; i < N; i++) {
			DFS(i);
		}
	}
	
	/*for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cout << dp[i][j] << '\t';
		}
		cout << endl;
	}*/

	cout << dp[N-1][N-1] << endl;

	return 0;
}