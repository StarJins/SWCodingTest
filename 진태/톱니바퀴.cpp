#include <iostream>
#include <string>

using namespace std;

int gear[5][8];
int check[4];
int k;

void Init() {
	for (int i = 1; i < 5; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < 8; j++) {
			gear[i][j] = temp[j] - '0';
		}
	}
}

void Check() {
	for (int i = 0; i < 4; i++)
		check[i] = 0;

	for (int i = 1; i < 4; i++) {
		if (gear[i][2] != gear[i + 1][6])
			check[i] = 1;
	}
}

void Rotate(int idx, int d) {
	if (d == 1) {	// 시계 방향
		int temp = gear[idx][7];
		for (int i = 7; i > 0; i--)
			gear[idx][i] = gear[idx][i - 1];
		gear[idx][0] = temp;
	}
	else {			// 반시계 방향
		int temp = gear[idx][0];
		for (int i = 0; i < 7; i++)
			gear[idx][i] = gear[idx][i + 1];
		gear[idx][7] = temp;
	}
}

void Run(int idx, int d) {
	Rotate(idx, d);	// 입력받은 톱니 돌리기

	int temp = d;
	for (int i = idx - 1; i >= 1; i--) {		// 왼쪽 톱니 극 확인해서 돌리기
		temp = (temp == -1) ? 1 : -1;
		if (check[i] == 1)
			Rotate(i, temp);				// 왼쪽 확인은 현재 인덱스 그대로
		else
			break;
	}

	temp = d;
	for (int i = idx; i < 4; i++) {			// 오른쪽 톱니 극 확인해서 돌리기
		temp = (temp == -1) ? 1 : -1;
		if (check[i] == 1)
			Rotate(i + 1, temp);			// 오른쪽 확인은 현재 인덱스에서 +1, check변수가 1-2, 2-3, 3-4 이렇게 묶어서 체크하기 때문이다
		else
			break;
	}
}

int Cal() {
	return gear[1][0] + gear[2][0] * 2 + gear[3][0] * 4 + gear[4][0] * 8;
}

int main() {
	Init();
	cin >> k;

	for (int i = 0; i < k; i++) {
		int idx, d;
		cin >> idx >> d;

		Check();		// 연결 극 확인
		Run(idx, d);	// 돌리기
	}

	cout << Cal();
	return 0;
}