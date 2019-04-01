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
		if (map[y][x] == 0) {	// ��ĭ�̶��
			map[y][x] = 2;		// û�����ֱ�
			ans++;
		}

		int nd = d;
		for (int i = 0; i < 4; i++) {
			nd = (nd - 1 == -1) ? 3 : nd - 1;	// �ݽð� �������� ȸ��
			int ny = y + dy[nd];
			int nx = x + dx[nd];

			if (map[ny][nx] == 0) {				// ��ĭ�� ���� �ִٸ� �̵� �� ó������
				y = ny, x = nx, d = nd;
				break;
			}
		}

		if(map[y][x] == 0)
			continue;

		int ny = y + dy[(d + 2) % 4];			// ���� ��ǥ
		int nx = x + dx[(d + 2) % 4];
		if (map[ny][nx] == 1)					// ������ ���� ���̶��
			break;								// ���߱�

		y = ny;									// �����ϴ� ���� ���� �ƴ϶�� �����ϱ�
		x = nx;
	}

	cout << ans;
	return 0;
}