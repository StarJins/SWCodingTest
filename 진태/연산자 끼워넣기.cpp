#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int numbers[11];
int visited[10];
int opIndex[4];
int oper[10];

int plusOp, minusOp, multiplyOp, divisionOp;

int n;

int maximum = -987654321;
int minimum = 987654321;

void Init() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> numbers[i];

	for (int i = 0; i < 4; i++)
		cin >> opIndex[i];

	// 각 연산 기호 인덱스 설정
	plusOp = opIndex[0] - 1;
	minusOp = opIndex[1] + plusOp;
	multiplyOp = opIndex[2] + minusOp;
	divisionOp = opIndex[3] + multiplyOp;

	for (int i = 0; i < n - 1; i++)
		oper[i] = -1;
}

void Cal() {
	stack<int> copyNum;

	for (int i = n - 1; i >= 0; i--)		// 계산용 숫자 복사
		copyNum.push(numbers[i]);

	for (int i = 0; i < n - 1; i++) {
		int val1 = copyNum.top(); copyNum.pop();
		int val2 = copyNum.top(); copyNum.pop();
		int op = oper[i];

		int res;
		switch (op) {
		case 0:
			res = val1 + val2;
			break;
		case 1:
			res = val1 - val2;
			break;
		case 2:
			res = val1 * val2;
			break;
		case 3:
			res = val1 / val2;
			break;
		}

		copyNum.push(res);
	}
	maximum = max(maximum, copyNum.top());
	minimum = min(minimum, copyNum.top());
}

int FindOp(int idx) {		// 각 인덱스에 맞게 연산자 반환
	if (idx <= plusOp)
		return 0;
	else if (plusOp < idx && idx <= minusOp)
		return 1;
	else if (minusOp < idx && idx <= multiplyOp)
		return 2;
	else
		return 3;
}

void DFS(int cnt) {
	if (cnt == n - 1) {
		Cal();
		return;
	}

	for (int i = 0; i < n - 1; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			int op = FindOp(i);
			oper[cnt] = op;

			DFS(cnt + 1);

			visited[i] = 0;
			oper[cnt] = -1;
		}
	}
}

int main() {
	Init();

	DFS(0);

	cout << maximum << endl << minimum;
	return 0;
}