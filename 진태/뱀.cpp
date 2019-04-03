#include <iostream>
#include <algorithm>
#include <queue>

#define MAX 102

using namespace std;

int map[MAX][MAX];
int sec = 0;
int	n, k, l;
int y = 1, x = 1, d = 1;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

queue<pair<int, int> > snake;
queue<pair<int, char> > moving;

void Init() {
	cin >> n;

	cin >> k;

	int ty, tx;
	for (int i = 0; i < k; i++) {
		cin >> ty >> tx;
		map[ty][tx] = 2;
	}

	cin >> l;
	char c;
	for (int i = 0; i < l; i++) {
		cin >> ty >> c;
		moving.push(make_pair(ty, c));
	}

	snake.push(make_pair(y, x));
	map[y][x] = 1;

	// �ܰ� �������
	for (int i = 0; i < n + 2; i++) {
		map[0][i] = 3;
		map[n + 1][i] = 3;
		map[i][0] = 3;
		map[i][n + 1] = 3;
	}
}

void Print() {
	cout << endl;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

bool Move() {
	y += dy[d];
	x += dx[d];


	pair<int, int> tail = snake.front();

	switch (map[y][x]) {
	case 3:				// ���̰ų� �ڱ� ���� ���
	case 1:
		return false;
	case 0:				// ��� ���� ĭ
		map[y][x] = 1;
		snake.push(make_pair(y, x));
		map[tail.first][tail.second] = 0;	// ���� ���ֱ�
		snake.pop();
		break;
	case 2:				// ��� �ִ� ĭ
		map[y][x] = 1;
		snake.push(make_pair(y, x));
		break;
	}
	return true;
}

int main() {
	Init();

	while (true) {
		sec++;
		bool valid = Move();
//		Print();
		if (valid == false)		// ���̳� �� ���� �ε����� ����
			break;

		if (!moving.empty()) {	// ȸ�� ����� ���� �ִٸ� ����
			if (sec == moving.front().first) {
				if (moving.front().second == 'D')
					d = (d + 1) % 4;
				else
					d = (d - 1 == -1) ? 3 : d - 1;

				moving.pop();
			}
		}
	}

	cout << sec;
	return 0;
}