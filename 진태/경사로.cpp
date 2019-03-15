#include <cstdio>
#include <algorithm>

using namespace std;

int map[100][100];
int slope[100][100];
int n, l;
int cnt;
bool road;
int ans = 0;

int main() {

	scanf("%d %d", &n, &l);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &map[i][j]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			slope[i][j] = 0;

	// ���� �� ��
	for (int i = 0; i < n; i++) {
		cnt = 1;
		road = true;
		for (int j = 0; j < n - 1; j++) {
			if (map[i][j] == map[i][j + 1]) {
				cnt++;
			}
			else if (abs(map[i][j] - map[i][j + 1]) == 1) {
				// �ٷ� �ڰ� �� ���� ��� ���ݱ��� ī��Ʈ�� �ŷ� ���� �Ǵ�
				if (map[i][j] < map[i][j + 1]) {
					int tmp = cnt;
					cnt = 1;
					if (tmp < l) {
						road = false;
						break;
					}
					// ���� �α�
					else {
						for (int k = 0; k < l; k++) {
							if (slope[i][j - k] == 0)
								slope[i][j - k] = 1;	// ���� ��ġ�� �� ������ ǥ��
							else {
								road = false;
								break;
							}
						}
					}
				}
				// �ٷ� �ڰ� �� ���� ���
				else {
					cnt = 1;
					int tmp = 1;
					for (int k = 1; k < l; k++) {	// �ڷ� �Ѿ�� ���� üũ
						if (map[i][j + k] == map[i][j + k + 1]) {
							tmp++;
						}
					}
					if (tmp < l) {
						road = false;
						break;
					}
					// ���� �α�
					else {
						for (int k = 0; k < l; k++) {
							if (slope[i][j + k + 1] == 0)
								slope[i][j + k + 1] = 1;
							else {
								road = false;
								break;
							}
						}
					}
				}
			}
			else {
				road = false;
				break;
			}
		}
		if (road == true) {
			ans++;
//			printf("i:%d\n", i);
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			slope[i][j] = 0;

	// ���� �� ��, ���ζ� �ε����� �ٸ���
	for (int j = 0; j < n; j++) {
		cnt = 1;
		road = true;
		for (int i = 0; i < n - 1; i++) {
			if (map[i][j] == map[i + 1][j]) {
				cnt++;
			}
			else if (abs(map[i][j] - map[i + 1][j]) == 1) {
				// �ٷ� �ڰ� �� ���� ���
				if (map[i][j] < map[i + 1][j]) {
					int tmp = cnt;
					cnt = 1;
					if (tmp < l) {
						road = false;
						break;
					}
					// ���� �α�
					else {
						for (int k = 0; k < l; k++) {
							if (slope[i - k][j] == 0)
								slope[i - k][j] = 1;
							else {
								road = false;
								break;
							}
						}
					}
				}
				// �ٷ� �ڰ� �� ���� ���
				else {
					cnt = 1;
					int tmp = 1;
					for (int k = 1; k < l; k++) {
						if (map[i + k][j] == map[i + k + 1][j]) {
							tmp++;
						}
					}
					if (tmp < l) {
						road = false;
						break;
					}
					// ���� �α�
					else {
						for (int k = 0; k < l; k++) {
							if (slope[i + k + 1][j] == 0)
								slope[i + k + 1][j] = 1;
							else {
								road = false;
								break;
							}
						}
					}
				}
			}
			else {
				road = false;
				break;
			}
		}
		if (road == true) {
			ans++;
//			printf("j:%d\n", j);
		}
	}

	printf("%d", ans);
	return 0;
}