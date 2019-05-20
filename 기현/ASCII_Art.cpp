#include <iostream>
using namespace std;

char ascii[400][400];

int main() {
	int n, m;
	int i, j;
	int r,g,b;
	int sum;

	cin >> n >> m;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> r >> g >> b;

			sum = 2126 * r + 7152 * g + 722 * b;
			
			if (sum < 510000)
				ascii[i][j] = 35;
			else if (sum >= 510000 && sum < 1020000)
				ascii[i][j] = 111;
			else if (sum >= 1020000 && sum < 1530000)
				ascii[i][j] = 43;
			else if (sum >= 1530000 && sum < 2040000)
				ascii[i][j] = 45;
			else
				ascii[i][j] = 46;
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cout << ascii[i][j];
		}
		cout << endl;
	}


}