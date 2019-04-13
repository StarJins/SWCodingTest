#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[501][501];
int p[502];

int n;

int Solve(int i, int j) {
	if (i == j) return 0;

	int &ret = dp[i][j];
	if (ret != -1) return ret;

	ret = 987654321;
	for (int k = i; k < j; k++) {
		ret = min(ret, Solve(i, k) + Solve(k + 1, j) + p[i]*p[k + 1]*p[j + 1]);	// 뒤에는 행렬을 곱한 다음에 필요한 합친 행렬의 곱 개수
	}
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		p[i] = a;
		p[i + 1] = b;
	}

	cout << Solve(0, n - 1);
	return 0;
}