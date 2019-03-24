#include <iostream>
#include <string>
#include <queue>

using namespace std;

int map[11][11];
int visited[11][11][11][11];

int n, m;
int ans = -1;
int hy, hx;
int iry, irx, iby, ibx;

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

struct points {
	int ry, rx, by, bx;
	int count;
};

void TestPrint() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

void Move(int &y, int &x, int d) {
	while (true) {
		y += dy[d], x += dx[d];
		if (map[y][x] == 1) {
			y -= dy[d];
			x -= dx[d];
			break;
		}
		else if (map[y][x] == 2)
			break;
	}
}

int main() {

	cin >> n >> m;

	// 숫자로 맵 변환
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < m; j++) {
			if (tmp[j] == '.') {
				map[i][j] = 0;
			}
			else if (tmp[j] == '#') {
				map[i][j] = 1;
			}
			else if (tmp[j] == 'O') {
				hy = i;
				hx = j;
				map[i][j] = 2;
			}
			else if (tmp[j] == 'R') {
				iry = i;
				irx = j;
			}
			else if (tmp[j] == 'B') {
				iby = i;
				ibx = j;
			}
		}
	}

	// BFS 활용
	queue<points> q;
	q.push({ iry, irx, iby, ibx, 0 });
	visited[iry][irx][iby][ibx] = 1;

	while (!q.empty()) {
		struct points p = q.front(); q.pop();

		if (p.count > 10)
			break;

		// 넓이 우선 탐색이기 때문에 정답을 찾으면 바로 break
		if (p.ry == hy && p.rx == hx) {
			ans = p.count;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nry = p.ry, nrx = p.rx;
			int nby = p.by, nbx = p.bx;

			Move(nry, nrx, i);
			Move(nby, nbx, i);

			if (nby == hy && nbx == hx)
				continue;

			if (nry == nby && nrx == nbx) {
				switch (i) {
				case 0:
					(p.ry > p.by) ? nry++ : nby++;
					break;
				case 1:
					(p.ry < p.by) ? nry-- : nby--;
					break;
				case 2:
					(p.rx > p.bx) ? nrx++ : nbx++;
					break;
				case 3:
					(p.rx < p.bx) ? nrx-- : nbx--;
					break;
				}
			}

			if (visited[nry][nrx][nby][nbx] == 0) {
				struct points tp = { nry, nrx, nby, nbx, p.count + 1 };
				q.push(tp);
				visited[nry][nrx][nby][nbx] = 1;
			}
		}
	}

	cout << ans;
	return 0;
}