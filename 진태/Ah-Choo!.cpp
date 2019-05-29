#include <iostream>
#include <algorithm>

using namespace std;

int n;
int x[2000];
int y[2000];
int dp[2000][2000];

void Init() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i];
	for (int i = 0; i < n; i++)
		cin >> y[i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dp[i][j] = -1;
}

int Solve(int i, int j) {
	if (i < 0 || j < 0)
		return 987654321;
	if (i == 0 && j == 0)
		return (x[i] - y[j])*(x[i] - y[j]);

	int &ret = dp[i][j];
	if (ret != -1)
		return ret;

	ret = (x[i] - y[j])*(x[i] - y[j]) + Solve(i - 1, j - 1);
	ret = min(ret, (x[i] - y[j])*(x[i] - y[j]) + Solve(i, j - 1));
	ret = min(ret, (x[i] - y[j])*(x[i] - y[j]) + Solve(i - 1, j));

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Init();

	cout << Solve(n - 1, n - 1);

	return 0;
}