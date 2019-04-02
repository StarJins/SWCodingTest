#include <iostream>

using namespace std;

int n, b, c;
int a[1000000];

long long int ans = 0;

void Init() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> b >> c;
}

int main() {
	Init();

	for (int i = 0; i < n; i++) {
		a[i] -= b;
		ans++;

		if (a[i] > 0) {		// 총 시험감독관이 감시하고 남은 사람 수가 있으면
			int needs = a[i] / c;
			if (a[i] % c != 0)
				needs++;

			ans += needs;
		}
	}
	cout << ans;
	return 0;
}