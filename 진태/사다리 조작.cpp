#include <iostream>
#include <algorithm>

using namespace std;

int map[31][12];	// 인덱싱 및 예외 방지를 위해 맵을 더 크게 선언
int n, m, h;
int ans = 987654321;

void LadderPrint() {
	for (int i = 1; i < h + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

// 가로줄 추가, 사다리 어느쪽으로 연결되어 있는지 1, 2로 구분, 1:왼쪽, 2:오른쪽
void AddRow(int a, int b) {
	map[a][b] = 1;
	map[a][b + 1] = 2;
}

// 가로줄 삭제
void RemoveRow(int a, int b) {
	map[a][b] = 0;
	map[a][b + 1] = 0;
}

bool Run() {
	// 세로줄 하나씩 테스트
	for (int j = 1; j < n + 1; j++) {
		int cur = j;
		for (int i = 1; i < h + 1; i++) {
			if (map[i][cur] == 1) {	// 가로줄의 왼쪽 만난 경우
				cur++;	// 오른쪽으로 가기
			}
			else if (map[i][cur] == 2) { // 가로줄의 오른쪽 만난 경우
				cur--;	// 왼쪽으로 가기
			}
		}
		if (cur != j)
			return false;
	}
	return true;
}

void DFS(int r, int cnt) {
	if (cnt == 3) {
		return;
	}

	// 처음부터 완전 탐색이기 때문에 이 전의 줄은 검사할 필요가 없다
	for (int i = r; i < h + 1; i++) {
		for (int j = 1; j < n; j++) {
			if (map[i][j] == 0 && map[i][j + 1] == 0) {
				AddRow(i, j);
				if (Run() == true)
					ans = min(ans, cnt + 1);
				DFS(i, cnt + 1);
				RemoveRow(i, j);
			}
		}
	}
}

int main() {
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		AddRow(a, b);
	}

	if (Run() == true)
		ans = 0;
	else {
		// 완전 탐색
		for (int i = 1; i < h + 1; i++) {
			for (int j = 1; j < n; j++) {
				if (map[i][j] == 0 && map[i][j + 1] == 0) {
					AddRow(i, j);
					if (Run() == true)
						ans = min(ans, 1);
					DFS(i, 1);
					RemoveRow(i, j);	// 백트레킹
				}
			}
		}
	}

	if (ans == 987654321)
		ans = -1;

	cout << ans;
	return 0;
}