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

	ret = max(Solve(day + 1), Solve(day + T[day]) + P[day]);	// dp[day]�ǹ� : day���� ����� ���� �� �� �ִ� �� �ִ�ġ, max(x, y)��� �ϸ� x�� �׳� ����� ������ ��, y�� ��� ���� ��
	return ret;
}

int main() {
	Init();

	cout << Solve(0);
	return 0;
}