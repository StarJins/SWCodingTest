#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 987654321

using namespace std;

int A[101][101], r, c, k;
int sizeR = 3, sizeC = 3;
int sec = 0;
pair<int, int> counter[101];

void Init() {
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			cin >> A[i][j];
}

void InitCounter() {
	for (int j = 1; j < 101; j++) {			// counter 초기화
		counter[j].first = 0;
		counter[j].second = 0;
	}
}

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}

void SortA() {
	if (sizeR >= sizeC) {
		for (int i = 1; i <= sizeR; i++) {
			InitCounter();

			for (int j = 1; j <= sizeC; j++) {		// counter에 숫자 개수 표시
				if (A[i][j] != 0) {
					counter[A[i][j]].first = A[i][j];
					counter[A[i][j]].second++;
				}
			}

			int col = 0;
			for (int j = 1; j < 101; j++) {			// 정렬을 위해 0 -> MAX로 변환
				if (counter[j].second == 0)
					counter[j].second = MAX;
				else
					col += 2;
			}
			sizeC = max(col, sizeC);

			stable_sort(counter + 1, counter + 101, cmp);	// 정렬

			for (int j = 1; j < 51; j++) {
				if (counter[j].second != MAX) {
					A[i][2 * j - 1] = counter[j].first;
					A[i][2 * j] = counter[j].second;
				}
				else {
					A[i][2 * j - 1] = 0;
					A[i][2 * j] = 0;
				}
			}
		}
	}
	else {
		for (int j = 1; j <= sizeC; j++) {
			InitCounter();

			for (int i = 1; i <= sizeR; i++) {		// counter에 숫자 개수 표시
				if (A[i][j] != 0) {
					counter[A[i][j]].first = A[i][j];
					counter[A[i][j]].second++;
				}
			}

			int row = 0;
			for (int i = 1; i < 101; i++) {			// 정렬을 위해 0 -> MAX로 변환
				if (counter[i].second == 0)
					counter[i].second = MAX;
				else
					row += 2;
			}
			sizeR = max(row, sizeR);

			stable_sort(counter + 1, counter + 101, cmp);	// 정렬

			for (int i = 1; i < 51; i++) {
				if (counter[i].second != MAX) {
					A[2 * i - 1][j] = counter[i].first;
					A[2 * i][j] = counter[i].second;
				}
				else {
					A[2 * i - 1][j] = 0;
					A[2 * i][j] = 0;
				}
			}
		}
	}
}

int main() {
	Init();

	bool asnwer = false;
	for (int i = 0; i < 101; i++) {
		if (A[r][c] == k) {
			asnwer = true;
			break;
		}

		SortA();

		sec++;
	}

	if (asnwer == false) sec = -1;
	cout << sec;
	return 0;
}