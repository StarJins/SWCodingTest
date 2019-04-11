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
vector<Tree> treeList[11][11];	// �� ��ġ�� ���� ���� vector

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
		treeList[y][x].push_back({ z, true });	// ���� �� ��ġ�� append
	}
}

void SpringSummer() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int total = 0;							// ���� ���� ��ġ�� �ڵ�
			vector<Tree> &cur = treeList[i][j];
			for (int k = 0; k < cur.size(); k++) {	// �� ��ġ���� ���� ���ڸ�ŭ �ݺ�
				if (map[i][j] >= cur[k].age && cur[k].live == true) {	// ����� ��� �����ϸ�
					map[i][j] -= cur[k].age;
					cur[k].age++;
				}
				else {													// �ƴϸ� �����
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

						if (1 <= ny && ny <= n && 1 <= nx && nx <= n) {	// ���� üũ
							vector<Tree> &next = treeList[ny][nx];
							next.insert(next.begin(), { 1, true });		// ���� �տ� �߰��ϱ�
						}
					}
				}
			}
			map[i][j] += A[i][j];	// �ܿ￡ �� ��
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