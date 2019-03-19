#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int lab[8][8];
int n, m;
int safe = 0;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

bool Check(int y, int x) {
	if (y < 0 || y >= n)
		return true;
	if (x < 0 || x >= m)
		return true;

	return false;
}

void Virus() {
	
	int virusLab[8][8];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			virusLab[i][j] = lab[i][j];
		}
	}

	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (virusLab[i][j] == 2)
				q.push(make_pair(i, j));
		}
	}

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (Check(ny, nx) == true)
				continue;

			if (virusLab[ny][nx] == 0) {
				virusLab[ny][nx] = 2;
				q.push(make_pair(ny, nx));
			}
		}
	}

	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (virusLab[i][j] == 0)
				count++;
		}
	}

	if (count > safe)
		safe = count;
}

void Wall(int numOfWall) {

	if (numOfWall == 3) {
		Virus();
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (lab[i][j] == 0) {
				lab[i][j] = 1;
				Wall(numOfWall+1);
				lab[i][j] = 0;
			}
		}
	}
}

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &lab[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (lab[i][j] == 0) {
				lab[i][j] = 1;
				Wall(1);
				lab[i][j] = 0;
			}
		}
	}

	printf("%d", safe);
	return 0;
}