#include <cstdio>
#include <algorithm>

using namespace std;

int map[500][500];
bool visited[500][500];
int n, m;
int ans = 0;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

// ㅗ 예외 블록
void Tmino() {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			int tmp1 = map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];
			int tmp2 = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1];
			int tmp = (tmp1 > tmp2) ? tmp1 : tmp2;
			ans = max(ans, tmp);
		}
	}
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			int tmp1 = map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1];
			int tmp2 = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j];
			int tmp = (tmp1 > tmp2) ? tmp1 : tmp2;
			ans = max(ans, tmp);
		}
	}
}

void DFS(int y, int x, int cnt, int sum) {
	if (cnt == 4) {
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		// map안에 있을 경우에만
		if (0 <= nx && nx < m && 0 <= ny && ny < n) {
			if (visited[ny][nx] == false) {
				visited[ny][nx] = true;
				DFS(ny, nx, cnt + 1, sum + map[ny][nx]);
				visited[ny][nx] = false;
			}
		}
	}
}

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = true;
			DFS(i, j, 1, map[i][j]);
			visited[i][j] = false;
		}
	}

	Tmino();

	printf("%d", ans);
	return 0;
}