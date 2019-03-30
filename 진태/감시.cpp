#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int map[9][9];
int ans = 987654321;

typedef struct {
	int y, x, type;
} cctv;

vector<cctv> v;
int numOfCctv;

int dy[] = { -1, 0, 1, 0 };	// �� ������ �Ʒ� ���� ����
int dx[] = { 0, 1, 0, -1 };

void Init();
void FindCCTV();
void Check();
void MapCopy(int copy[][9], int original[][9]);
bool MapCheck(int y, int x);
void Sight(int y, int x, int d);
void DFS(int cnt);
void Two(cctv cur, int cnt);
void One(cctv cur, int cnt);
void Four(cctv cur, int cnt);

int main() {
	Init();
	FindCCTV();	// CCTV ��ǥ �� type Ȯ��

	if (numOfCctv == 0) {	// 0���� ��� �ٷ� �簢���� üũ
		Check();
	}
	else {
		cctv cur = v[0];
		switch (cur.type) {	// �� Ÿ�Կ� �°� ó��
		case 2:
			Two(cur, 0);
			break;
		case 5:
			One(cur, 0);
			break;
		default:
			Four(cur, 0);
		}
	}
	cout << ans;
	return 0;
}

void Init() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
}

void FindCCTV() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 || map[i][j] == 2 || map[i][j] == 3 || map[i][j] == 4 || map[i][j] == 5) {
				v.push_back({ i, j, map[i][j] });
			}
		}
	}
	numOfCctv = v.size();
}

void Check() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0)
				cnt++;
		}
	}
	ans = min(ans, cnt);
}

void MapCopy(int copy[][9], int original[][9]) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			copy[i][j] = original[i][j];
}

bool MapCheck(int y, int x) {
	if (0 <= y && y < n && 0 <= x && x < m)
		return true;
	else
		return false;
}

void Sight(int y, int x, int d) {
	while (true) {
		y += dy[d], x += dx[d];	// �Ű����� ���� �� �Ʒ� �� �� ����
		if (MapCheck(y, x) == false || map[y][x] == 6)	// ���̳� ������ ������ ��
			break;

		map[y][x] = 9;	// �簢���� �ƴ� �� 9�� ġȯ
	}
}

void DFS(int cnt) {
	if (cnt == numOfCctv) {	// ��ü cctv �þ� Ȯ�� �� ������ �簡���� üũ
		Check();
		return;
	}

	cctv cur = v[cnt];	// Ÿ�Կ� �°� �Ѱ��ֱ�
	switch (cur.type) {
	case 2:
		Two(cur, cnt);
		break;
	case 5:
		One(cur, cnt);
		break;
	default:
		Four(cur, cnt);
	}
}

void Two(cctv cur, int cnt) {
	for (int i = 0; i < 2; i++) {	// i==0 -> ��, �Ʒ�, i==1 -> ����, ��
		int copy[9][9];
		MapCopy(copy, map);

		Sight(cur.y, cur.x, i);
		Sight(cur.y, cur.x, (i + 2) % 4);
		DFS(cnt + 1);	// DFS�� ���� cctv �þ� Ȯ���ϱ�

		MapCopy(map, copy);
	}
}

void One(cctv cur, int cnt) {
	int copy[9][9];
	MapCopy(copy, map);

	for (int i = 0; i < 4; i++)	// 4���� �ѹ��� Ȯ��
		Sight(cur.y, cur.x, i);
	DFS(cnt + 1);

	MapCopy(map, copy);
}

void Four(cctv cur, int cnt) {
	for (int i = 0; i < 4; i++) {
		int copy[9][9];
		MapCopy(copy, map);

		Sight(cur.y, cur.x, i);	// 1, 3, 4Ÿ���� cctv�� �⺻������ ���� Ȯ��(���� ó���� �ܿ�)
		if (cur.type == 3)						// 3�̸� ������ �߰�
			Sight(cur.y, cur.x, (i + 1) % 4);
		else if (cur.type == 4) {				// 4�̸� ������, ���� �߰�
			Sight(cur.y, cur.x, (i + 1) % 4);
			Sight(cur.y, cur.x, (i + 3) % 4);
		}
		DFS(cnt + 1);

		MapCopy(map, copy);
	}
}