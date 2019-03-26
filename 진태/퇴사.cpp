#include <iostream>
#include <algorithm>

using namespace std;

int t[16], p[16];
int n;
int ans = 0;

void DFS(int day, int pay) {
	if (day > n) {
		ans = max(ans, pay);
		return;
	}

	for (int i = day; i <= n; i++) {
		int next = i;	// 현재 요일
		for (int j = 0; j < t[i] - 1; j++) {
			next++;	// 상담해야 하는 일 수 만큼 요일 증가
			if (next > n) {
				ans = max(ans, pay);
				break;
			}
		}
		if (next <= n) {
			DFS(next + 1, pay + p[i]);	// 번 돈 더하기
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}

	for (int i = 1; i <= n; i++) {
		int next = i;	// 현재 요일
		for (int j = 0; j < t[i] - 1; j++) {
			next++;	// 상담해야 하는 일 수 만큼 요일 증가
			if (next > n)
				break;
		}
		if (next <= n) {
			DFS(next + 1, p[i]);	// 번 돈 더하기
		}
	}

	cout << ans;
	return 0;
}