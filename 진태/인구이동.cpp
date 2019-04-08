#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

typedef struct {
	int y, x;
} Point;

int map[50][50];
int visited[50][50];
int ans = 0;
bool open;

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

int n, l, r;

void Init() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
}

void BFS(int y, int x, int region) {
	int total = map[y][x], cnt = 1;		// �α� �̵��� ���� ���� total ���

	queue<Point> q;
	q.push({ y, x });
	visited[y][x] = region;

	while (!q.empty()) {
		Point p = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = p.y + dy[i];
			int nx = p.x + dx[i];

			if ((0 <= ny && ny < n && 0 <= nx && nx < n)) {
				if (visited[ny][nx] == 0) {							// ���� ���տ��� Ȯ���� ���߰�
					int diff = abs(map[p.y][p.x] - map[ny][nx]);
					if (l <= diff && diff <= r) {					// ���� ������ �ȴٸ�
						total += map[ny][nx];						// ���� ��ü �α����� ���ϰ�
						cnt++;										// ���� ī��Ʈ

						q.push({ ny, nx });
						visited[ny][nx] = region;

						if (open == false) {
							ans++;			// �α��̵� �����ϴϱ� ����++
							open = true;
						}
					}
				}
			}
		}
	}

	if (cnt != 1) {		// ������ ȥ���� ��� �α��̵��� �ʿ䰡 ����
		total /= cnt;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (visited[i][j] == region)
					map[i][j] = total;
	}
}

void Check() {
	open = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
		}
	}

	// ���պ��� ����
	int region = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0) {
				region++;
				BFS(i, j, region);
			}
		}
	}
}

int main() {
	Init();

	while (true) {
		Check();
		if (open == false)
			break;
	}

	cout << ans;
	return 0;
}