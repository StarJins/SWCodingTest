#include <iostream>
#include <climits>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
int ans = INT_MAX;

int hy, hx;

typedef struct {
	int y[2], x[2], success[2];	// 0:RED, 1:BLUE
	char map[11][11];
} change;

change original;

void MapInit() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> original.map[i][j];
}

void LocateInit() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (original.map[i][j] == 'R') {
				original.y[0] = i;
				original.x[0] = j;
			}
			else if (original.map[i][j] == 'B') {
				original.y[1] = i;
				original.x[1] = j;
			}
			else if (original.map[i][j] == 'O') {
				hy = i;
				hx = j;
			}
		}
	}
}

void Copy(change *c) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			c->map[i][j] = original.map[i][j];
		}
		c->map[i][m] = '\0';
	}

	for (int i = 0; i < 2; i++) {
		c->y[i] = original.y[i];
		c->x[i] = original.x[i];
		c->success[i] = original.success[i];
	}
}

void Rollback(change c) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			original.map[i][j] = c.map[i][j];
		}
		original.map[i][m] = '\0';
	}

	for (int i = 0; i < 2; i++) {
		original.y[i] = c.y[i];
		original.x[i] = c.x[i];
		original.success[i] = c.success[i];
	}
}

void Up(int color, int first) {
	original.map[original.y[color]][original.x[color]] = '.';

	char cur = (color == 0) ? 'R' : 'B';
	char other = (color == 0) ? 'B' : 'R';

	for (int i = original.y[color] - 1; i >= 0; i--) {
		if (original.map[i][original.x[color]] == '#') {
			original.map[i + 1][original.x[color]] = cur;
			original.y[color] = i + 1;
			break;
		}
		// 나중에 움직인 구슬 앞에 먼저 움직인 구슬이 있을 때
		else if (first != color && original.map[i][original.x[color]] == other) {
			original.map[i + 1][original.x[color]] = cur;
			original.y[color] = i + 1;
			break;
		}
		else if (original.map[i][original.x[color]] == 'O') {
			original.success[color] = 1;
			break;
		}
	}
}

void Down(int color, int first) {
	original.map[original.y[color]][original.x[color]] = '.';

	char cur = (color == 0) ? 'R' : 'B';
	char other = (color == 0) ? 'B' : 'R';

	for (int i = original.y[color] + 1; i < n; i++) {
		if (original.map[i][original.x[color]] == '#') {
			original.map[i - 1][original.x[color]] = cur;
			original.y[color] = i - 1;
			break;
		}
		// 나중에 움직인 구슬 앞에 먼저 움직인 구슬이 있을 때
		else if (first != color && original.map[i][original.x[color]] == other) {
			original.map[i - 1][original.x[color]] = cur;
			original.y[color] = i - 1;
			break;
		}
		else if (original.map[i][original.x[color]] == 'O') {
			original.success[color] = 1;
			break;
		}
	}
}

void Left(int color, int first) {
	original.map[original.y[color]][original.x[color]] = '.';

	char cur = (color == 0) ? 'R' : 'B';
	char other = (color == 0) ? 'B' : 'R';

	for (int j = original.x[color] - 1; j >= 0; j--) {
		if (original.map[original.y[color]][j] == '#') {
			original.map[original.y[color]][j + 1] = cur;
			original.x[color] = j + 1;
			break;
		}
		// 나중에 움직인 구슬 앞에 먼저 움직인 구슬이 있을 때
		else if (first != color && original.map[original.y[color]][j] == other) {
			original.map[original.y[color]][j + 1] = cur;
			original.x[color] = j + 1;
			break;
		}
		else if (original.map[original.y[color]][j] == 'O') {
			original.success[color] = 1;
			break;
		}
	}
}

void Right(int color, int first) {
	original.map[original.y[color]][original.x[color]] = '.';

	char cur = (color == 0) ? 'R' : 'B';
	char other = (color == 0) ? 'B' : 'R';

	for (int j = original.x[color] + 1; j < m; j++) {
		if (original.map[original.y[color]][j] == '#') {
			original.map[original.y[color]][j - 1] = cur;
			original.x[color] = j - 1;
			break;
		}
		// 나중에 움직인 구슬 앞에 먼저 움직인 구슬이 있을 때
		else if (first != color && original.map[original.y[color]][j] == other) {
			original.map[original.y[color]][j - 1] = cur;
			original.x[color] = j - 1;
			break;
		}
		else if (original.map[original.y[color]][j] == 'O') {
			original.success[color] = 1;
			break;
		}
	}
}

void Move(int direction) {
	// 0: Up, 1: Down, 2: Left, 3: Right

	int first;
	// 움직일 때 같은 선상에 있으면 앞에 있는 구슬 먼저 움직여야 한다.
	switch (direction) {
	case 0:
		if (original.y[0] < original.y[1])
			first = 0;
		else
			first = 1;
		break;
	case 1:
		if (original.y[0] > original.y[1])
			first = 0;
		else
			first = 1;
		break;
	case 2:
		if (original.x[0] < original.x[1])
			first = 0;
		else
			first = 1;
		break;
	case 3:
		if (original.x[0] > original.x[1])
			first = 0;
		else
			first = 1;
	}

	int curColor = first;
	for (int i = 0; i < 2; i++) {
		switch (direction) {
		case 0:
			Up(curColor, first);
			break;
		case 1:
			Down(curColor, first);
			break;
		case 2:
			Left(curColor, first);
			break;
		case 3:
			Right(curColor, first);
		}
		curColor = (curColor == 0) ? 1 : 0;
	}
}

int Oposite(int i) {
	if (i == 0) return 1;
	else if (i == 1) return 0;
	else if (i == 2) return 3;
	else return 2;
}

void DFS(int d, int cnt) {
	if (original.success[0] == 1 && original.success[1] == 0) {
		ans = min(ans, cnt);
		return;
	}
	if (cnt == 11 || (original.success[0] == 1 && original.success[1] == 1) || (original.success[0] == 0 && original.success[1] == 1))
		return;

	for (int i = 0; i < 4; i++) {
		if (d == i || Oposite(d) == i)
			continue;
		
		change copy;
		Copy(&copy);
		Move(i);
		DFS(i, cnt + 1);
		Rollback(copy);
	}
}

int main() {
	cin >> n >> m;
	MapInit();
	LocateInit();

	for (int i = 0; i < 4; i++) {
		change copy;
		Copy(&copy);
		Move(i);
		DFS(i, 1);
		Rollback(copy);
	}

	// 10번 이하로 답을 찾지 못한 경우
	if (ans == INT_MAX)
		ans = -1;

	cout << ans;
	return 0;
}