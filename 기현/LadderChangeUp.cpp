#include <iostream>
#include <algorithm>

using namespace std;
int mNum[270][2];
int usable[270][2];
int Ladder[30][9] = { 0 };
int ans = -1;
int uNum = 0;
int N, M, H;
int test = 0;

void print() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N - 1; j++) {
			cout << Ladder[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
}

void Swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void copyLadder(int copy[][9], int origin[][9]) {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N - 1; j++) {
			copy[i][j] = origin[i][j];
		}
	}
}

void copyResult(int copy[10], int origin[10]) {
	for (int i = 0; i < N; i++)
		copy[i] = origin[i];
}

void DFS(int cnt, int k, int result[10]) {
	int copyL[30][9];
	int copyR[10];
	int dummyResult[10];
	bool flag = true;

	if(ans != -1 && cnt >= ans)
		return;

	if (k == uNum) {
		return;
	}

	if (k == 0) {
		for (int i = 0; i < usable[0][0]; i++) {
			for (int j = 0; j < N - 1; j++) {
				if (Ladder[i][j] == 1) {
					Swap(result[j], result[j + 1]);
				}
			}
		}
	}
	else if(usable[k - 1][0] != usable[k][0]){
		for (int i = usable[k - 1][0]; i < usable[k][0]; i++) {
			for (int j = 0; j < N - 1; j++) {
				if (Ladder[i][j] == 1 || Ladder[i][j] == 2) {
					Swap(result[j], result[j + 1]);
				}
			}
		}
	}
	

	for (int i = 0; i < N; i++)
		copyR[i] = result[i];

	for (int i = usable[k][0]; i < H; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (Ladder[i][j] == 1) {
				Swap(copyR[j], copyR[j + 1]);
			}
			else if (Ladder[i][j] == 2) {
				int tmp = i;
				for (int m = tmp - 1; m >= 0; m--) {
					if (Ladder[m][j] == 1 || Ladder[m][j + 1] == 1 || Ladder[m][j - 1] == 1 || Ladder[m][j + 1] == 2 || Ladder[m][j - 1] == 2) {
						Swap(copyR[j], copyR[j + 1]);
						break;
					}
					else if (Ladder[m][j] == 2)
						return;
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (copyR[i] != i) {
			flag = false;
			break;
		}
	}

	if (flag == true) {
		if (ans == -1)
			ans = cnt;
		else
			ans = min(ans, cnt);
		return;
	}
	else {
		
		copyLadder(copyL, Ladder);
		copyResult(dummyResult, result);
		Ladder[usable[k][0]][usable[k][1]] = 2;
		if(usable[k][0] == usable[k+1][0] && usable[k][1] == usable[k + 1][1] - 1)
			DFS(cnt + 1, k + 2, result);
		else {
			DFS(cnt + 1, k + 1, result);
		}
		copyResult(result, dummyResult);
		copyLadder(Ladder, copyL);

		copyLadder(copyL, Ladder);
		copyResult(dummyResult, result);
		DFS(cnt, k + 1, result);
		copyLadder(Ladder, copyL);
		copyResult(result, dummyResult);
		
	}
}

int main() {
	int x, y;
	int result[10];
	
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		mNum[i][0] = x - 1;
		mNum[i][1] = y - 1;
	}
	
	for (int i = 0; i < M; i++) {
		Ladder[mNum[i][0]][mNum[i][1]] = 1;

		if (N == 2) {}
		else if (N == 3) {
			if (mNum[i][0] == 0)
				Ladder[mNum[i][0]][1] = -1;
			else
				Ladder[mNum[i][0]][0] = -1;
		}
		else {
			if (mNum[i][1] != N - 1)
				Ladder[mNum[i][0]][mNum[i][1] + 1] = -1;
			if (mNum[i][1] != 0)
				Ladder[mNum[i][0]][mNum[i][1] - 1] = -1;
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (Ladder[i][j] == 0) {
				usable[uNum][0] = i;
				usable[uNum][1] = j;
				uNum++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		result[i] = i;
		
	}

	DFS(0,0, result);
	cout << ans << endl;

	return 0;
}