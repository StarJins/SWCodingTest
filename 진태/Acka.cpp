#include <iostream>
#define MOD 1000000007
using namespace std;

int s, a, b, c;

int dp[51][51][51][51];

int Solve(int n, int A, int B, int C) {
	if (n == 0) {
		if (A == 0 && B == 0 && C == 0) return 1;
		else return 0;
	}
	if (A < 0 || B < 0 || C < 0) return 0;
	if (A + B + C < n) return 0;

	int &ret = dp[n][A][B][C];
	if (ret != -1) return ret;

	ret = Solve(n - 1, A - 1, B, C);
	ret %= MOD;
	ret += Solve(n - 1, A, B - 1, C);
	ret %= MOD;
	ret += Solve(n - 1, A, B, C - 1);
	ret %= MOD;
	ret += Solve(n - 1, A - 1, B - 1, C);
	ret %= MOD;
	ret += Solve(n - 1, A - 1, B, C - 1);
	ret %= MOD;
	ret += Solve(n - 1, A, B - 1, C - 1);
	ret %= MOD;
	ret += Solve(n - 1, A - 1, B - 1, C - 1);
	ret %= MOD;

	return ret;
}

int main() {
	cin >> s >> a >> b >> c;

	for(int i=0;i<=s;i++)
		for (int j = 0; j <= s; j++)
			for (int k = 0; k <= s; k++)
				for (int l = 0; l <= s; l++)
					dp[i][j][k][l] = -1;

	cout << Solve(s, a, b, c);
	return 0;
}