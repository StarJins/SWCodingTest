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

		if (a[i] > 0) {		// �� ���谨������ �����ϰ� ���� ��� ���� ������
			int needs = a[i] / c;
			if (a[i] % c != 0)
				needs++;

			ans += needs;
		}
	}
	cout << ans;
	return 0;
}