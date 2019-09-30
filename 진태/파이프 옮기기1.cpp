#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int map[20][20];

typedef struct _Pipe {
	int y1, x1, y2, x2, dir;	// dir 0: 가로, 1: 세로, 2: 대각선

	_Pipe() {}
	_Pipe(int _y1, int _x1, int _y2, int _x2, int _dir) { y1 = _y1; x1 = _x1; y2 = _y2; x2 = _x2; dir = _dir; }
} Pipe;
int ans;

int dy[3][3] = { {0, 99, 1}, {99, 2, 2}, {1, 2, 2} };
int dx[3][3] = { {2, 99, 2}, {99, 0, 1}, {2, 1, 2} };

void Init() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	ans = 0;
}

void BFS() {
	queue<Pipe> q;
	q.push(Pipe(1, 1, 1, 2, 0));

	while (!q.empty()) {
		Pipe cur = q.front(); q.pop();
		int y1 = cur.y1;
		int x1 = cur.x1;
		int y2 = cur.y2;
		int x2 = cur.x2;
		int dir = cur.dir;

		if (y2 == n && x2 == n) {
			ans++;
			continue;
		}

		int ny1, nx1, ny2, nx2;
		ny1 = y2;
		nx1 = x2;

		for (int i = 0; i < 3; i++) {
			ny2 = y1 + dy[dir][i];
			nx2 = x1 + dx[dir][i];

			if ((1 <= ny1 && ny1 <= n && 1 <= nx1 && nx1 <= n) && (1 <= ny2 && ny2 <= n && 1 <= nx2 && nx2 <= n)) {
				if (map[ny2][nx2] == 0) {
					if (i == 2) {
						if (map[ny2 - 1][nx2] == 0 && map[ny2][nx2 - 1] == 0) {
							q.push(Pipe(ny1, nx1, ny2, nx2, i));
						}
					}
					else {
						q.push(Pipe(ny1, nx1, ny2, nx2, i));
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Init();
	BFS();

	cout << ans;

	return 0;
}