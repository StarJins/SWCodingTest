#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct {
	int age;
	bool live;
} Tree;

int map[11][11];
int A[11][11];
vector<Tree> treeList[11][11];	// 각 위치에 담을 나무 vector

int n, m, k;

int dy[] = { -1, 1, 0, 0, 1, -1, 1, -1 };
int dx[] = { 0, 0, -1, 1, 1, -1, -1, 1 };

void Init() {
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = 5;
			cin >> A[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		int y, x, z;
		cin >> y >> x >> z;
		treeList[y][x].push_back({ z, true });	// 나무 각 위치에 append
	}
}

void SpringSummer() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int total = 0;							// 죽은 나무 합치는 코드
			vector<Tree> &cur = treeList[i][j];
			for (int k = 0; k < cur.size(); k++) {	// 각 위치에서 나무 숫자만큼 반복
				if (map[i][j] >= cur[k].age && cur[k].live == true) {	// 영양분 흡수 가능하면
					map[i][j] -= cur[k].age;
					cur[k].age++;
				}
				else {													// 아니면 지우기
					total += cur[k].age / 2;
					cur.erase(cur.begin() + k);
					k--;
				}
			}
			map[i][j] += total;
		}
	}
}

void FallWinter() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			vector<Tree> &cur = treeList[i][j];
			for (int k = 0; k < cur.size(); k++) {
				if (cur[k].age % 5 == 0) {
					for (int l = 0; l < 8; l++) {
						int ny = i + dy[l];
						int nx = j + dx[l];

						if (1 <= ny && ny <= n && 1 <= nx && nx <= n) {	// 범위 체크
							vector<Tree> &next = treeList[ny][nx];
							next.insert(next.begin(), { 1, true });		// 제일 앞에 추가하기
						}
					}
				}
			}
			map[i][j] += A[i][j];	// 겨울에 할 일
		}
	}
}

int main() {
	Init();

	for (int a = 0; a < k; a++) {
		SpringSummer();
		FallWinter();

	}


	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			vector<Tree> &cur = treeList[i][j];
			for (int k = 0; k < cur.size(); k++) {
				if (cur[k].live == true) {
					ans++;
				}
			}
		}
	}

	cout << ans;
	return 0;
}