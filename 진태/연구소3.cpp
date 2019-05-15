#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

int map[51][51];
int visited[10];
int n, m;
int ans = INF, blank = 0;

int dy[] = { 0, 0, -1, 1 };
int dx[] = { -1, 1, 0, 0 };

vector<pair<int, int> > virus;

typedef struct {
	int y, x, sec;
} element;

void Init() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) blank++;
			else if (map[i][j] == 2) virus.push_back(make_pair(i, j));
		}
	}
}

void mapCopy(int a[][51], int b[][51]) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = b[i][j];
}

void Print(int copy[][51]) {
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << copy[i][j] << ' ';
		}
		cout << endl;
	}
}

int BFS() {
	int copy[51][51];
	mapCopy(copy, map);

	queue<element> q;
	for (int i = 0; i < virus.size(); i++) {
		if (visited[i] == 1) {
			q.push({ virus[i].first, virus[i].second, 0 });
			map[virus[i].first][virus[i].second] = 9;
		}
	}

	int ret_sec = 0, addVirus = 0;;
	while (!q.empty()) {
		if (blank == addVirus)
			break;

		element cur = q.front(); q.pop();
		int y = cur.y;
		int x = cur.x;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (0 <= ny && ny < n && 0 <= nx && nx < n) {
				if (copy[ny][nx] == 0 || copy[ny][nx] == 2) {
					if (copy[ny][nx] == 0) addVirus++;

					copy[ny][nx] = 9;
					q.push({ ny, nx, cur.sec + 1 });
					ret_sec = cur.sec + 1;
				}
			}
		}
	}

//	Print(copy);

	if (blank == addVirus)
		return ret_sec;

	return INF;
}

void DFS(int cnt, int cur) {
	if (cnt == m) {
		ans = min(ans, BFS());
		return;
	}

	for (int i = cur + 1; i < virus.size(); i++) {
		visited[i] = 1;
		DFS(cnt + 1, i);
		visited[i] = 0;
	}
}

int main() {
	Init();
	DFS(0, -1);

	if (ans == INF) ans = -1;
	cout << ans;
	return 0;
}