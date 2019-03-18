#include <cstdio>

using namespace std;

int map[20][20];
int n, m, x, y, k;
int go;

int dx[] = {0, 0, 0, -1, 1 };
int dy[] = {0, 1, -1, 0, 0 };

int left = 4;
int right = 3;
int top = 1;
int bottom = 6;
int front = 5;
int back = 2;

int dice[7];

bool IsValid(int d) {
	int nx = x + dx[d];
	int ny = y + dy[d];

	if (0 > nx || nx >= n)
		return false;
	if (0 > ny || ny >= m)
		return false;

	return true;
}

void Rolling(int d) {
	int temp;

	switch (d) {
	case 1:
		temp = top;
		top = left;
		left = bottom;
		bottom = right;
		right = temp;
		break;
	case 2:
		temp = top;
		top = right;
		right = bottom;
		bottom = left;
		left = temp;
		break;
	case 3:
		temp = top;
		top = front;
		front = bottom;
		bottom = back;
		back = temp;
		break;
	case 4:
		temp = top;
		top = back;
		back = bottom;
		bottom = front;
		front = temp;
	}
}

void Move(int direction) {
	if (IsValid(direction) == true) {
		x += dx[direction];
		y += dy[direction];

		Rolling(direction);

		if (map[x][y] == 0) {
			map[x][y] = dice[bottom];
		}
		else {
			dice[bottom] = map[x][y];
			map[x][y] = 0;
		}

		printf("%d\n", dice[top]);
	}
}

int main() {
	scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);

	for (int i = 0; i < k; i++) {
		scanf("%d", &go);

		Move(go);
	}

	return 0;
}