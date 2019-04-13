#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int dp[51][51][51][3][3];
string s;
bool printed = false;

int Solve(int n, int a, int b, int c, string ans, int p, int pp) {
	if (n == s.length()) {
		if (a == 0 && b == 0 && c == 0) {
			if (printed == false) {
				printed = true;
				cout << ans;
			}
			return 1;
		}
		else return 0;
	}

	if (a < 0 || b < 0 || c < 0) return 0;
	if (a + b + c < 0) return 0;

	int &ret = dp[a][b][c][p][pp];
	if (ret != -1) return ret;

	ret = Solve(n + 1, a - 1, b, c, ans + 'A', pp, 0);

	if (!(n > 0 && (ans[n - 1] == 'B')))
		ret = Solve(n + 1, a, b - 1, c, ans + 'B', pp, 1);

	if (!(n > 0 && (ans[n - 1] == 'C')) && !(n > 1 && (ans[n - 2] == 'C')))
		ret = Solve(n + 1, a, b, c - 1, ans + 'C', pp, 2);

	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));

	cin >> s;

	int a = 0, b = 0, c = 0;
	for (int i = 0; i < s.length(); i++) {
		switch (s[i]) {
		case 'A': a++; break;
		case 'B': b++; break;
		case 'C': c++; break;
		}
	}

	Solve(0, a, b, c, "", 0, 0);

	if (printed == false) cout << "-1";

	return 0;
}