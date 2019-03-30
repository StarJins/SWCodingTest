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

int dy[] = { -1, 0, 1, 0 };	// 위 오른쪽 아래 왼쪽 순서
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
	FindCCTV();	// CCTV 좌표 및 type 확인

	if (numOfCctv == 0) {	// 0개인 경우 바로 사각지대 체크
		Check();
	}
	else {
		cctv cur = v[0];
		switch (cur.type) {	// 각 타입에 맞게 처리
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
		y += dy[d], x += dx[d];	// 매개변수 따라 위 아래 왼 오 진행
		if (MapCheck(y, x) == false || map[y][x] == 6)	// 벽이나 밖으로 나가면 끝
			break;

		map[y][x] = 9;	// 사각지대 아닌 곳 9로 치환
	}
}

void DFS(int cnt) {
	if (cnt == numOfCctv) {	// 전체 cctv 시야 확인 다 했으면 사가지대 체크
		Check();
		return;
	}

	cctv cur = v[cnt];	// 타입에 맞게 넘겨주기
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
	for (int i = 0; i < 2; i++) {	// i==0 -> 위, 아래, i==1 -> 오른, 왼
		int copy[9][9];
		MapCopy(copy, map);

		Sight(cur.y, cur.x, i);
		Sight(cur.y, cur.x, (i + 2) % 4);
		DFS(cnt + 1);	// DFS로 다음 cctv 시야 확인하기

		MapCopy(map, copy);
	}
}

void One(cctv cur, int cnt) {
	int copy[9][9];
	MapCopy(copy, map);

	for (int i = 0; i < 4; i++)	// 4방향 한번에 확인
		Sight(cur.y, cur.x, i);
	DFS(cnt + 1);

	MapCopy(map, copy);
}

void Four(cctv cur, int cnt) {
	for (int i = 0; i < 4; i++) {
		int copy[9][9];
		MapCopy(copy, map);

		Sight(cur.y, cur.x, i);	// 1, 3, 4타입의 cctv는 기본적으로 위쪽 확인(제일 처음인 겨우)
		if (cur.type == 3)						// 3이면 오른쪽 추가
			Sight(cur.y, cur.x, (i + 1) % 4);
		else if (cur.type == 4) {				// 4이면 오른쪽, 왼쪽 추가
			Sight(cur.y, cur.x, (i + 1) % 4);
			Sight(cur.y, cur.x, (i + 3) % 4);
		}
		DFS(cnt + 1);

		MapCopy(map, copy);
	}
}