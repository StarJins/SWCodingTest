#include <cstdio>

using namespace std;

int map[500][500];
int n, m;
int ans = 0;

// 모든 블록의 모든 좌표 계산해서 최댓값 찾기
void Omino() {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {
			int tmp = map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1];
			if (tmp > ans)
				ans = tmp;
		}
	}
}

void Imino() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m - 3; j++) {
			int tmp = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i][j + 3];
			if (tmp > ans)
				ans = tmp;
		}
	}
	for (int i = 0; i < n - 3; i++) {
		for (int j = 0; j < m; j++) {
			int tmp = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 3][j];
			if (tmp > ans)
				ans = tmp;
		}
	}
}

void Lmino() {
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			int tmp1 = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j + 1];
			int tmp2 = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1];
			int tmp = (tmp1 > tmp2) ? tmp1 : tmp2;
			if (tmp > ans)
				ans = tmp;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			int tmp1 = map[i][j + 2] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];
			int tmp2 = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j];
			int tmp = (tmp1 > tmp2) ? tmp1 : tmp2;
			if (tmp > ans)
				ans = tmp;
		}
	}
}

void Jmino() {
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			int tmp1 = map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j] + map[i + 2][j + 1];
			int tmp2 = map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 2][j];
			int tmp = (tmp1 > tmp2) ? tmp1 : tmp2;
			if (tmp > ans)
				ans = tmp;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			int tmp1 = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];
			int tmp2 = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 2];
			int tmp = (tmp1 > tmp2) ? tmp1 : tmp2;
			if (tmp > ans)
				ans = tmp;
		}
	}
}

void Smino() {
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			int tmp = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1];
			if (tmp > ans)
				ans = tmp;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			int tmp = map[i][j + 1] + map[i][j + 2] + map[i + 1][j] + map[i + 1][j + 1];
			if (tmp > ans)
				ans = tmp;
		}
	}
}

void Zmino() {
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			int tmp = map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j];
			if (tmp > ans)
				ans = tmp;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			int tmp = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2];
			if (tmp > ans)
				ans = tmp;
		}
	}
}

void Tmino() {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			int tmp1 = map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];
			int tmp2 = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1];
			int tmp = (tmp1 > tmp2) ? tmp1 : tmp2;
			if (tmp > ans)
				ans = tmp;
		}
	}
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			int tmp1 = map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1];
			int tmp2 = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j];
			int tmp = (tmp1 > tmp2) ? tmp1 : tmp2;
			if (tmp > ans)
				ans = tmp;
		}
	}
}

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);

	Omino();
	Imino();
	Lmino();
	Jmino();
	Smino();
	Zmino();
	Tmino();

	printf("%d", ans);
	return 0;
}