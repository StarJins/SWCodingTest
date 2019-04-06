#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int map[51][51];
int n, m;
int ans = 987654321;
int visited[13];

typedef struct {
	int y, x, minCost;
} h;

typedef struct {
	int y, x;
} ck;

vector<h> house;
vector<ck> ckLocate;
int numOfh;
int numOfCk;

void Init() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	// ��, ġŲ�� ��ġ ����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1)
				house.push_back({ i, j, 987654321 });
			else if (map[i][j] == 2)
				ckLocate.push_back({ i, j });
		}
	}
	numOfh = house.size();
	numOfCk = ckLocate.size();
}

void Cal() {
	for (int i = 0; i < numOfh; i++)
		house[i].minCost = 987654321;	// �� ������ �ּҰŸ��� ���� ��� �� �ʱ�ȭ

	for (int i = 0; i < numOfCk; i++) {
		if (visited[i] == 1) {
			for (int j = 0; j < numOfh; j++) {	// ��� ���� �ش��ϴ� ġŲ�Ÿ� ���ϱ�
				int hy, hx, cy, cx;
				hy = house[j].y;
				hx = house[j].x;
				cy = ckLocate[i].y;
				cx = ckLocate[i].x;

				int res = abs(hy - cy) + abs(hx - cx);
				house[j].minCost = min(house[j].minCost, res);	// �ּ� ġŲ�Ÿ� ����
			}
		}
	}

	int total = 0;
	for (int i = 0; i < numOfh; i++)
		total += house[i].minCost;
	ans = min(ans, total);				// �ּ� ���� ġŲ�Ÿ� ����
}

void DFS(int cnt, int cur) {
	if (cnt == m) {
		Cal();
		return;
	}

	for (int i = cur + 1; i < numOfCk; i++) {	// ��� m�� ���� ��Ȳ ���ؼ� DFS ���
		if (visited[i] == 0) {
			visited[i] = 1;
			DFS(cnt + 1, i);
			visited[i] = 0;
		}
	}
}

int main() {
	Init();

	DFS(0, -1);

	cout << ans;
	return 0;
}