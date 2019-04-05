#include <iostream>
#include <algorithm>

using namespace std;

int numbers[11];
int opIndex[4];

int n;

int maximum = -987654321;
int minimum = 987654321;

void Init() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> numbers[i];

	for (int i = 0; i < 4; i++)
		cin >> opIndex[i];
}

void DFS(int cnt, int p, int m, int t, int d, int result) {
	if (cnt == n) {
		maximum = max(maximum, result);
		minimum = min(minimum, result);
		return;
	}

	
	if (p < opIndex[0]) {
		DFS(cnt + 1, p + 1, m, t, d, result + numbers[cnt]);
	}
	if (m < opIndex[1]) {
		DFS(cnt + 1, p, m + 1, t, d, result - numbers[cnt]);
	}
	if (t < opIndex[2]) {
		DFS(cnt + 1, p, m, t + 1, d, result * numbers[cnt]);
	}
	if (d < opIndex[3]) {
		DFS(cnt + 1, p, m, t, d + 1, result / numbers[cnt]);
	}
}

int main() {
	Init();

	DFS(1, 0, 0, 0, 0, numbers[0]);

	cout << maximum << endl << minimum;
	return 0;
}