#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int map[21][21];
int n;
int ans = 0;

// ������ �� ����Ʈ
void Print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%4d", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

// �� ���� �Լ�
void MapCopy(int copy[][21], int orig[][21]) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			copy[i][j] = orig[i][j];
}

// �ű�� ���̶� ������ �˻�, ������ true
bool IsSame(int a[][21], int b[][21]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] != b[i][j])
				return false;
		}
	}
	return true;
}

// ������ �ű�鼭 �����ִ� �Լ�
bool Move(int direction) {
	int prevMap[21][21];
	MapCopy(prevMap, map);	// �����̱��� �� ����

	int tmp[21];	// ���� �����

	// Direction - 0:up, 1:down, 2:left, 3:right
	switch (direction) {
	case 0:	// Up
		for (int j = 0; j < n; j++) {	// ��� �迭 �ʱ�ȭ
			for (int k = 0; k < 21; k++)
				tmp[k] = 0;
			int idx = 0;				// ��� �迭 index ����
			int prev = map[0][j];
			tmp[idx] = prev;

			// ��ġ��
			for (int i = 1; i < n; i++) {
				if (map[i][j] == 0)	// 0 ����
					continue;
				else if (prev == map[i][j]) {	// �����ſ� ������ ���ؼ� tmp�� ����, �ߺ� ������ ���� ���� �ε��� �̵�
					tmp[idx++] = prev + map[i][j];
					i++;
				}
				else {
					/*
						���� ��� ���� �ű�µ�
						0 0 0
						2 0 0
						2 0 0
						�϶�, ������ 0��° �ڸ� ���� tmp�� ù��° ������ �־���� 0�� �� �ְ�,
						�Ʒ� ������ ������ 0�� ���ڸ��� �ƴ� ������ �ν��� ������ tmp�� 4 0 0�� �ƴ� 0 4 0�� ���� ��
					*/
					if (tmp[idx] != 0)
						idx++;
				}

				// �ε����� �߰��ϴٺ��� �� ������ ���� ���� �־ ���� �߰�
				if (i < n) {
					prev = map[i][j];
					tmp[idx] = prev;
				}
			}

			// map���� ����
			for (int i = 0; i < n; i++)
				map[i][j] = tmp[i];
		}
//		Print();
		break;
	// case 1~3�� �ε��� ��길 �ٸ��� �ϰ�, ��� ��Ŀ������ ����
	case 1:	// Down
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 21; k++)	// ��� �迭 �ʱ�ȭ
				tmp[k] = 0;
			int idx = 0;					// ��� �迭 index ����
			int prev = map[n - 1][j];
			tmp[idx] = prev;

			// ��ġ��
			for (int i = n - 2; i >= 0; i--) {
				if (map[i][j] == 0)
					continue;
				else if (prev == map[i][j]) {
					tmp[idx++] = prev + map[i][j];
					i--;
				}
				else {
					if(tmp[idx] != 0)
						idx++;
				}

				if (i >= 0) {
					prev = map[i][j];
					tmp[idx] = prev;
				}
			}

			// map���� ����
			for (int i = 0; i < n; i++)
				map[n - 1 - i][j] = tmp[i];
		}
//		Print();
		break;
	case 2:	// Left
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < 21; k++)	// ��� �迭 �ʱ�ȭ
				tmp[k] = 0;
			int idx = 0;					// ��� �迭 index ����
			int prev = map[i][0];
			tmp[idx] = prev;

			// ��ġ��
			for (int j = 1; j < n; j++) {
				if (map[i][j] == 0)
					continue;
				else if (prev == map[i][j]) {
					tmp[idx++] = prev + map[i][j];
					j++;
				}
				else {
					if (tmp[idx] != 0)
						idx++;
				}

				if (j < n) {
					prev = map[i][j];
					tmp[idx] = prev;
				}
			}

			// map���� ����
			for (int j = 0; j < n; j++)
				map[i][j] = tmp[j];
		}
//		Print();
		break;
	case 3:	// Right
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < 21; k++)	// ��� �迭 �ʱ�ȭ
				tmp[k] = 0;
			int idx = 0;					// ��� �迭 index ����
			int prev = map[i][n-  1];
			tmp[idx] = prev;

			// ��ġ��
			for (int j = n - 2; j >= 0; j--) {
				if (map[i][j] == 0)
					continue;
				else if (prev == map[i][j]) {
					tmp[idx++] = prev + map[i][j];
					j--;
				}
				else {
					if (tmp[idx] != 0)
						idx++;
				}

				if (j >= 0) {
					prev = map[i][j];
					tmp[idx] = prev;
				}
			}

			// map���� ����
			for (int j = 0; j < n; j++)
				map[i][n - 1 - j] = tmp[j];
		}
//		Print();
		break;
	}

	return IsSame(prevMap, map);	// ���� ����ġ���� �� ����Ϸ� ������, ���ص� 1�ʾȿ� �ذ�Ǽ� ��� ����
}

// �ִ� ��� ã��
void FindMax() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans = max(ans, map[i][j]);
		}
	}
}

void DFS(int cnt) {
	int restore[21][21];

	// ���� ����
	if (cnt == 5) {
		FindMax();
		return;
	}

	for (int i = 0; i < 4; i++) {
		MapCopy(restore, map);
		Move(i);	// �����̰�
		DFS(cnt + 1);
		MapCopy(map, restore);	// ��Ʈ��ŷ
	}
}

int main() {
	int restore[21][21];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &map[i][j]);

	if (n == 1)
		ans = map[0][0];
	else {
		for (int i = 0; i < 4; i++) {
			MapCopy(restore, map);
			Move(i);	// �����̰�
			DFS(1);
			MapCopy(map, restore);	// ��Ʈ��ŷ
		}
	}

	printf("%d", ans);
	return 0;
}