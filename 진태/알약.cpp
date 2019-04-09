#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long int dp[30][30];

long long int Solve(int w, int h) {
	if (w < 0 || h < 0) return 0;	// ¿À´ä ÄÉÀÌ½º
	if (w == 0 && h == 0) return 1;	// Á¤´ä ÄÉÀÌ½º

	long long int &ret = dp[w][h];
	if (ret != -1) return ret;

	ret = Solve(w - 1, h + 1) + Solve(w, h - 1);	// ¸ÖÂÄÇÑ°É ¹Ý ÂÉ°¶¶§¶û, ¹ÝÂÉ°µ°É ¸ÔÀ»¶§·Î ±¸ºÐ
	return ret;
}

void Init() {
	// dp ÃÊ±âÈ­
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
			dp[i][j] = -1;
}

int main() {
	int n;
	vector<long long int> ans;
	while (true) {
		Init();
		cin >> n;
		if (n == 0) break;
		ans.push_back(Solve(n - 1, 1));
	}

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	return 0;
}