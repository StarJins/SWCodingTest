#include <iostream>
#include <algorithm>

using namespace std;

int map[31][12];	// �ε��� �� ���� ������ ���� ���� �� ũ�� ����
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

// ������ �߰�, ��ٸ� ��������� ����Ǿ� �ִ��� 1, 2�� ����, 1:����, 2:������
void AddRow(int a, int b) {
	map[a][b] = 1;
	map[a][b + 1] = 2;
}

// ������ ����
void RemoveRow(int a, int b) {
	map[a][b] = 0;
	map[a][b + 1] = 0;
}

bool Run() {
	// ������ �ϳ��� �׽�Ʈ
	for (int j = 1; j < n + 1; j++) {
		int cur = j;
		for (int i = 1; i < h + 1; i++) {
			if (map[i][cur] == 1) {	// �������� ���� ���� ���
				cur++;	// ���������� ����
			}
			else if (map[i][cur] == 2) { // �������� ������ ���� ���
				cur--;	// �������� ����
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

	// ó������ ���� Ž���̱� ������ �� ���� ���� �˻��� �ʿ䰡 ����
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
		// ���� Ž��
		for (int i = 1; i < h + 1; i++) {
			for (int j = 1; j < n; j++) {
				if (map[i][j] == 0 && map[i][j + 1] == 0) {
					AddRow(i, j);
					if (Run() == true)
						ans = min(ans, 1);
					DFS(i, 1);
					RemoveRow(i, j);	// ��Ʈ��ŷ
				}
			}
		}
	}

	if (ans == 987654321)
		ans = -1;

	cout << ans;
	return 0;
}