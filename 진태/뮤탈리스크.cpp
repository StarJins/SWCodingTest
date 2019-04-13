#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[61][61][61];
int n;
int scv[3];

int Solve(int a, int b, int c) {
	if (a <= 0 && b <= 0 && c <= 0) return 0;

	a = (a < 0) ? 0 : a;
	b = (b < 0) ? 0 : b;
	c = (c < 0) ? 0 : c;

	int &ret = dp[a][b][c];
	if (ret != -1) return ret;

	ret = 987654321;
	ret = min(ret, Solve(a - 9, b - 3, c - 1) + 1);
	ret = min(ret, Solve(a - 9, b - 1, c - 3) + 1);
	ret = min(ret, Solve(a - 3, b - 9, c - 1) + 1);
	ret = min(ret, Solve(a - 1, b - 9, c - 3) + 1);
	ret = min(ret, Solve(a - 3, b - 1, c - 9) + 1);
	ret = min(ret, Solve(a - 1, b - 3, c - 9) + 1);

	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> scv[i];

	cout << Solve(scv[0], scv[1], scv[2]);

	return 0;
}