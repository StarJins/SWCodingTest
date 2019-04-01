#include <iostream>

using namespace std;

int map[51][51];
int ans = 0;

int n, m;
int y, x, d;

// index 0: Up, 1: Right, 2: Down, 3: Left
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void Init() {
	cin >> n >> m;
	cin >> y >> x >> d;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
}

int main() {
	Init();

	while (true) {
		if (map[y][x] == 0) {	// 빈칸이라면
			map[y][x] = 2;		// 청소해주기
			ans++;
		}

		int nd = d;
		for (int i = 0; i < 4; i++) {
			nd = (nd - 1 == -1) ? 3 : nd - 1;	// 반시계 방향으로 회전
			int ny = y + dy[nd];
			int nx = x + dx[nd];

			if (map[ny][nx] == 0) {				// 빈칸인 곳이 있다면 이동 후 처음으로
				y = ny, x = nx, d = nd;
				break;
			}
		}

		if(map[y][x] == 0)
			continue;

		int ny = y + dy[(d + 2) % 4];			// 후진 좌표
		int nx = x + dx[(d + 2) % 4];
		if (map[ny][nx] == 1)					// 후진할 곳이 벽이라면
			break;								// 멈추기

		y = ny;									// 후진하는 곳이 벽이 아니라면 후진하기
		x = nx;
	}

	cout << ans;
	return 0;
}