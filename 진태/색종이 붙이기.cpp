#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_MAP 10

int map[MAX_MAP + 1][MAX_MAP + 1];
int numOfOne, ans;

void Init() {
	numOfOne = 0;

	for (int i = 0; i < MAX_MAP; i++) {
		for (int j = 0; j < MAX_MAP; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) numOfOne++;
		}
	}

	ans = 987654321;
}

void CopyMap(int ori[][MAX_MAP + 1], int des[][MAX_MAP + 1]) {
	for (int i = 0; i < MAX_MAP; i++)
		for (int j = 0; j < MAX_MAP; j++)
			des[i][j] = ori[i][j];
}

void Solve(int curPaperSize, int useNumOfPaper, int canUse) {
	if (curPaperSize == 0) {
		if (numOfOne == 0) {
			ans = min(ans, useNumOfPaper);
		}
		return;
	}

	int saveMap[MAX_MAP + 1][MAX_MAP + 1], saveNumOfOne;

	if (canUse > 0) {
		// (i, j): start point
		for (int i = 0; i < MAX_MAP - curPaperSize; i++) {
			for (int j = 0; j < MAX_MAP - curPaperSize; j++) {
				// check to can cover using current paper
				int flag = 1;
				for (int r = 0; r < curPaperSize; r++) {
					for (int c = 0; c < curPaperSize; c++) {
						// cannot cover
						if (map[i + r][j + c] == 0) {
							flag = 0;
							break;
						}
					}
					if (flag == 0) break;
				}


				if (flag == 1) {
					CopyMap(map, saveMap);
					saveNumOfOne = numOfOne;

					for (int r = 0; r < curPaperSize; r++) {
						for (int c = 0; c < curPaperSize; c++) {
							map[i + r][j + c] = 0;
							numOfOne--;
						}
					}

					Solve(curPaperSize, useNumOfPaper + 1, canUse - 1);

					CopyMap(saveMap, map);
					numOfOne = saveNumOfOne;
				}
			}
		}
	}

	Solve(curPaperSize - 1, useNumOfPaper, 5);

}

int main() {
	Init();
	if (numOfOne > 0) Solve(5, 0, 5);
	else ans = 0;

	if (ans == 987654321) ans = -1;
	cout << ans;
	return 0;
}