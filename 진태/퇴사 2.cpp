#include <iostream>
#include <algorithm>

using namespace std;

int n;
int T[1500000], P[1500000], dp[1500000];

void Init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> T[i] >> P[i];
		dp[i] = -1;
	}
}

int Solve(int day) {
	if (day > n)
		return -987654321;
	if (day == n)
		return 0;
	
	int &ret = dp[day];
	if (ret != -1)
		return ret;

	ret = max(Solve(day + 1), Solve(day + T[day]) + P[day]);	// dp[day]의미 : day부터 퇴사일 까지 벌 수 있는 돈 최대치, max(x, y)라고 하면 x는 그날 상담을 안했을 떄, y는 삼당 했을 때
	return ret;
}

int main() {
	Init();

	cout << Solve(0);
	return 0;
}