#include <iostream>
#include <string>
#include <vector>

using namespace std;

char topPlane[3][3];
char bottomPlane[3][3];
char leftPlane[3][3];
char rightPlane[3][3];
char frontPlane[3][3];
char backPlane[3][3];

int n;

void CubeInit() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			topPlane[i][j] = 'w';
			bottomPlane[i][j] = 'y';
			leftPlane[i][j] = 'g';
			rightPlane[i][j] = 'b';
			frontPlane[i][j] = 'r';
			backPlane[i][j] = 'o';
		}
	}
}

void Top(char d) {
	char temp[3];

	if (d == '+') {
		// top말고 영향받는 다른 면 회전
		temp[0] = rightPlane[0][0];
		temp[1] = rightPlane[0][1];
		temp[2] = rightPlane[0][2];

		rightPlane[0][0] = backPlane[2][2];
		rightPlane[0][1] = backPlane[2][1];
		rightPlane[0][2] = backPlane[2][0];

		backPlane[2][0] = leftPlane[0][2];
		backPlane[2][1] = leftPlane[0][1];
		backPlane[2][2] = leftPlane[0][0];

		leftPlane[0][0] = frontPlane[0][0];
		leftPlane[0][1] = frontPlane[0][1];
		leftPlane[0][2] = frontPlane[0][2];

		frontPlane[0][0] = temp[0];
		frontPlane[0][1] = temp[1];
		frontPlane[0][2] = temp[2];

		// top 자체 회전 - 이 뒤의 함수도 전부 이 순서
		// 코너 회전
		temp[0] = topPlane[0][0];
		topPlane[0][0] = topPlane[2][0];
		topPlane[2][0] = topPlane[2][2];
		topPlane[2][2] = topPlane[0][2];
		topPlane[0][2] = temp[0];

		// 엣지 회전
		temp[0] = topPlane[0][1];
		topPlane[0][1] = topPlane[1][0];
		topPlane[1][0] = topPlane[2][1];
		topPlane[2][1] = topPlane[1][2];
		topPlane[1][2] = temp[0];
	}
	else {
		temp[0] = leftPlane[0][0];
		temp[1] = leftPlane[0][1];
		temp[2] = leftPlane[0][2];

		leftPlane[0][0] = backPlane[2][2];
		leftPlane[0][1] = backPlane[2][1];
		leftPlane[0][2] = backPlane[2][0];

		backPlane[2][0] = rightPlane[0][2];
		backPlane[2][1] = rightPlane[0][1];
		backPlane[2][2] = rightPlane[0][0];

		rightPlane[0][0] = frontPlane[0][0];
		rightPlane[0][1] = frontPlane[0][1];
		rightPlane[0][2] = frontPlane[0][2];

		frontPlane[0][0] = temp[0];
		frontPlane[0][1] = temp[1];
		frontPlane[0][2] = temp[2];

		temp[0] = topPlane[0][0];
		topPlane[0][0] = topPlane[0][2];
		topPlane[0][2] = topPlane[2][2];
		topPlane[2][2] = topPlane[2][0];
		topPlane[2][0] = temp[0];

		temp[0] = topPlane[0][1];
		topPlane[0][1] = topPlane[1][2];
		topPlane[1][2] = topPlane[2][1];
		topPlane[2][1] = topPlane[1][0];
		topPlane[1][0] = temp[0];
	}
}

void Bottom(char d) {
	char temp[3];

	if (d == '+') {
		temp[0] = leftPlane[2][0];
		temp[1] = leftPlane[2][1];
		temp[2] = leftPlane[2][2];

		leftPlane[2][0] = backPlane[0][2];
		leftPlane[2][1] = backPlane[0][1];
		leftPlane[2][2] = backPlane[0][0];

		backPlane[0][0] = rightPlane[2][2];
		backPlane[0][1] = rightPlane[2][1];
		backPlane[0][2] = rightPlane[2][0];

		rightPlane[2][0] = frontPlane[2][0];
		rightPlane[2][1] = frontPlane[2][1];
		rightPlane[2][2] = frontPlane[2][2];

		frontPlane[2][0] = temp[0];
		frontPlane[2][1] = temp[1];
		frontPlane[2][2] = temp[2];

		temp[0] = bottomPlane[0][0];
		bottomPlane[0][0] = bottomPlane[2][0];
		bottomPlane[2][0] = bottomPlane[2][2];
		bottomPlane[2][2] = bottomPlane[0][2];
		bottomPlane[0][2] = temp[0];

		temp[0] = bottomPlane[0][1];
		bottomPlane[0][1] = bottomPlane[1][0];
		bottomPlane[1][0] = bottomPlane[2][1];
		bottomPlane[2][1] = bottomPlane[1][2];
		bottomPlane[1][2] = temp[0];
	}
	else {
		temp[0] = rightPlane[2][0];
		temp[1] = rightPlane[2][1];
		temp[2] = rightPlane[2][2];

		rightPlane[2][0] = backPlane[0][2];
		rightPlane[2][1] = backPlane[0][1];
		rightPlane[2][2] = backPlane[0][0];

		backPlane[0][0] = leftPlane[2][2];
		backPlane[0][1] = leftPlane[2][1];
		backPlane[0][2] = leftPlane[2][0];

		leftPlane[2][0] = frontPlane[2][0];
		leftPlane[2][1] = frontPlane[2][1];
		leftPlane[2][2] = frontPlane[2][2];

		frontPlane[2][0] = temp[0];
		frontPlane[2][1] = temp[1];
		frontPlane[2][2] = temp[2];

		temp[0] = bottomPlane[0][0];
		bottomPlane[0][0] = bottomPlane[0][2];
		bottomPlane[0][2] = bottomPlane[2][2];
		bottomPlane[2][2] = bottomPlane[2][0];
		bottomPlane[2][0] = temp[0];

		temp[0] = bottomPlane[0][1];
		bottomPlane[0][1] = bottomPlane[1][2];
		bottomPlane[1][2] = bottomPlane[2][1];
		bottomPlane[2][1] = bottomPlane[1][0];
		bottomPlane[1][0] = temp[0];
	}
}

void Front(char d) {
	char temp[3];

	if (d == '+') {
		temp[0] = leftPlane[0][2];
		temp[1] = leftPlane[1][2];
		temp[2] = leftPlane[2][2];

		leftPlane[0][2] = bottomPlane[0][0];
		leftPlane[1][2] = bottomPlane[0][1];
		leftPlane[2][2] = bottomPlane[0][2];

		bottomPlane[0][0] = rightPlane[2][0];
		bottomPlane[0][1] = rightPlane[1][0];
		bottomPlane[0][2] = rightPlane[0][0];

		rightPlane[0][0] = topPlane[2][0];
		rightPlane[1][0] = topPlane[2][1];
		rightPlane[2][0] = topPlane[2][2];

		topPlane[2][0] = temp[2];
		topPlane[2][1] = temp[1];
		topPlane[2][2] = temp[0];

		temp[0] = frontPlane[0][0];
		frontPlane[0][0] = frontPlane[2][0];
		frontPlane[2][0] = frontPlane[2][2];
		frontPlane[2][2] = frontPlane[0][2];
		frontPlane[0][2] = temp[0];

		temp[0] = frontPlane[0][1];
		frontPlane[0][1] = frontPlane[1][0];
		frontPlane[1][0] = frontPlane[2][1];
		frontPlane[2][1] = frontPlane[1][2];
		frontPlane[1][2] = temp[0];
	}
	else {
		temp[0] = rightPlane[0][0];
		temp[1] = rightPlane[1][0];
		temp[2] = rightPlane[2][0];

		rightPlane[0][0] = bottomPlane[0][2];
		rightPlane[1][0] = bottomPlane[0][1];
		rightPlane[2][0] = bottomPlane[0][0];

		bottomPlane[0][0] = leftPlane[0][2];
		bottomPlane[0][1] = leftPlane[1][2];
		bottomPlane[0][2] = leftPlane[2][2];

		leftPlane[0][2] = topPlane[2][2];
		leftPlane[1][2] = topPlane[2][1];
		leftPlane[2][2] = topPlane[2][0];

		topPlane[2][0] = temp[0];
		topPlane[2][1] = temp[1];
		topPlane[2][2] = temp[2];

		temp[0] = frontPlane[0][0];
		frontPlane[0][0] = frontPlane[0][2];
		frontPlane[0][2] = frontPlane[2][2];
		frontPlane[2][2] = frontPlane[2][0];
		frontPlane[2][0] = temp[0];

		temp[0] = frontPlane[0][1];
		frontPlane[0][1] = frontPlane[1][2];
		frontPlane[1][2] = frontPlane[2][1];
		frontPlane[2][1] = frontPlane[1][0];
		frontPlane[1][0] = temp[0];
	}
}

void Back(char d) {
	char temp[3];

	if (d == '+') {
		temp[0] = rightPlane[0][2];
		temp[1] = rightPlane[1][2];
		temp[2] = rightPlane[2][2];

		rightPlane[0][2] = bottomPlane[2][2];
		rightPlane[1][2] = bottomPlane[2][1];
		rightPlane[2][2] = bottomPlane[2][0];

		bottomPlane[2][0] = leftPlane[0][0];
		bottomPlane[2][1] = leftPlane[1][0];
		bottomPlane[2][2] = leftPlane[2][0];

		leftPlane[0][0] = topPlane[0][2];
		leftPlane[1][0] = topPlane[0][1];
		leftPlane[2][0] = topPlane[0][0];

		topPlane[0][0] = temp[0];
		topPlane[0][1] = temp[1];
		topPlane[0][2] = temp[2];

		temp[0] = backPlane[0][0];
		backPlane[0][0] = backPlane[2][0];
		backPlane[2][0] = backPlane[2][2];
		backPlane[2][2] = backPlane[0][2];
		backPlane[0][2] = temp[0];

		temp[0] = backPlane[0][1];
		backPlane[0][1] = backPlane[1][0];
		backPlane[1][0] = backPlane[2][1];
		backPlane[2][1] = backPlane[1][2];
		backPlane[1][2] = temp[0];
	}
	else {
		temp[0] = leftPlane[0][0];
		temp[1] = leftPlane[1][0];
		temp[2] = leftPlane[2][0];

		leftPlane[0][0] = bottomPlane[2][0];
		leftPlane[1][0] = bottomPlane[2][1];
		leftPlane[2][0] = bottomPlane[2][2];

		bottomPlane[2][0] = rightPlane[2][2];
		bottomPlane[2][1] = rightPlane[1][2];
		bottomPlane[2][2] = rightPlane[0][2];

		rightPlane[0][2] = topPlane[0][0];
		rightPlane[1][2] = topPlane[0][1];
		rightPlane[2][2] = topPlane[0][2];

		topPlane[0][0] = temp[2];
		topPlane[0][1] = temp[1];
		topPlane[0][2] = temp[0];

		temp[0] = backPlane[0][0];
		backPlane[0][0] = backPlane[0][2];
		backPlane[0][2] = backPlane[2][2];
		backPlane[2][2] = backPlane[2][0];
		backPlane[2][0] = temp[0];

		temp[0] = backPlane[0][1];
		backPlane[0][1] = backPlane[1][2];
		backPlane[1][2] = backPlane[2][1];
		backPlane[2][1] = backPlane[1][0];
		backPlane[1][0] = temp[0];
	}
}

void Left(char d) {
	char temp[3];

	if (d == '+') {
		temp[0] = backPlane[0][0];
		temp[1] = backPlane[1][0];
		temp[2] = backPlane[2][0];

		backPlane[0][0] = bottomPlane[0][0];
		backPlane[1][0] = bottomPlane[1][0];
		backPlane[2][0] = bottomPlane[2][0];

		bottomPlane[0][0] = frontPlane[0][0];
		bottomPlane[1][0] = frontPlane[1][0];
		bottomPlane[2][0] = frontPlane[2][0];

		frontPlane[0][0] = topPlane[0][0];
		frontPlane[1][0] = topPlane[1][0];
		frontPlane[2][0] = topPlane[2][0];

		topPlane[0][0] = temp[0];
		topPlane[1][0] = temp[1];
		topPlane[2][0] = temp[2];

		temp[0] = leftPlane[0][0];
		leftPlane[0][0] = leftPlane[2][0];
		leftPlane[2][0] = leftPlane[2][2];
		leftPlane[2][2] = leftPlane[0][2];
		leftPlane[0][2] = temp[0];

		temp[0] = leftPlane[0][1];
		leftPlane[0][1] = leftPlane[1][0];
		leftPlane[1][0] = leftPlane[2][1];
		leftPlane[2][1] = leftPlane[1][2];
		leftPlane[1][2] = temp[0];
	}
	else {
		temp[0] = frontPlane[0][0];
		temp[1] = frontPlane[1][0];
		temp[2] = frontPlane[2][0];

		frontPlane[0][0] = bottomPlane[0][0];
		frontPlane[1][0] = bottomPlane[1][0];
		frontPlane[2][0] = bottomPlane[2][0];

		bottomPlane[0][0] = backPlane[0][0];
		bottomPlane[1][0] = backPlane[1][0];
		bottomPlane[2][0] = backPlane[2][0];

		backPlane[0][0] = topPlane[0][0];
		backPlane[1][0] = topPlane[1][0];
		backPlane[2][0] = topPlane[2][0];

		topPlane[0][0] = temp[0];
		topPlane[1][0] = temp[1];
		topPlane[2][0] = temp[2];

		temp[0] = leftPlane[0][0];
		leftPlane[0][0] = leftPlane[0][2];
		leftPlane[0][2] = leftPlane[2][2];
		leftPlane[2][2] = leftPlane[2][0];
		leftPlane[2][0] = temp[0];

		temp[0] = leftPlane[0][1];
		leftPlane[0][1] = leftPlane[1][2];
		leftPlane[1][2] = leftPlane[2][1];
		leftPlane[2][1] = leftPlane[1][0];
		leftPlane[1][0] = temp[0];
	}
}

void Right(char d) {
	char temp[3];

	if (d == '+') {
		temp[0] = frontPlane[0][2];
		temp[1] = frontPlane[1][2];
		temp[2] = frontPlane[2][2];

		frontPlane[0][2] = bottomPlane[0][2];
		frontPlane[1][2] = bottomPlane[1][2];
		frontPlane[2][2] = bottomPlane[2][2];

		bottomPlane[0][2] = backPlane[0][2];
		bottomPlane[1][2] = backPlane[1][2];
		bottomPlane[2][2] = backPlane[2][2];

		backPlane[0][2] = topPlane[0][2];
		backPlane[1][2] = topPlane[1][2];
		backPlane[2][2] = topPlane[2][2];

		topPlane[0][2] = temp[0];
		topPlane[1][2] = temp[1];
		topPlane[2][2] = temp[2];

		temp[0] = rightPlane[0][0];
		rightPlane[0][0] = rightPlane[2][0];
		rightPlane[2][0] = rightPlane[2][2];
		rightPlane[2][2] = rightPlane[0][2];
		rightPlane[0][2] = temp[0];

		temp[0] = rightPlane[0][1];
		rightPlane[0][1] = rightPlane[1][0];
		rightPlane[1][0] = rightPlane[2][1];
		rightPlane[2][1] = rightPlane[1][2];
		rightPlane[1][2] = temp[0];
	}
	else {
		temp[0] = backPlane[0][2];
		temp[1] = backPlane[1][2];
		temp[2] = backPlane[2][2];

		backPlane[0][2] = bottomPlane[0][2];
		backPlane[1][2] = bottomPlane[1][2];
		backPlane[2][2] = bottomPlane[2][2];

		bottomPlane[0][2] = frontPlane[0][2];
		bottomPlane[1][2] = frontPlane[1][2];
		bottomPlane[2][2] = frontPlane[2][2];

		frontPlane[0][2] = topPlane[0][2];
		frontPlane[1][2] = topPlane[1][2];
		frontPlane[2][2] = topPlane[2][2];

		topPlane[0][2] = temp[0];
		topPlane[1][2] = temp[1];
		topPlane[2][2] = temp[2];

		temp[0] = rightPlane[0][0];
		rightPlane[0][0] = rightPlane[0][2];
		rightPlane[0][2] = rightPlane[2][2];
		rightPlane[2][2] = rightPlane[2][0];
		rightPlane[2][0] = temp[0];

		temp[0] = rightPlane[0][1];
		rightPlane[0][1] = rightPlane[1][2];
		rightPlane[1][2] = rightPlane[2][1];
		rightPlane[2][1] = rightPlane[1][0];
		rightPlane[1][0] = temp[0];
	}
}

void Rotate(string rotate) {
	char plane = rotate[0];
	char direction = rotate[1];

	switch (plane) {
	case 'U':
		Top(direction);
		break;
	case 'D':
		Bottom(direction);
		break;
	case 'F':
		Front(direction);
		break;
	case 'B':
		Back(direction);
		break;
	case 'L':
		Left(direction);
		break;
	case 'R':
		Right(direction);
		break;
	}
}

void TopPrint() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << topPlane[i][j];
		}
		cout << endl;
	}
}

int main() {
	vector<int> numCubing;
	vector<string> howRotate;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int cubing;
		cin >> cubing;
		numCubing.push_back(cubing);

		for (int j = 0; j < cubing; j++) {
			string rotate;
			cin >> rotate;
			howRotate.push_back(rotate);
		}
	}

	int idx = 0;
	for (int i = 0; i < n; i++) {
		CubeInit();

		for (int j = 0; j < numCubing[i]; j++) {
			Rotate(howRotate[j + idx]);
		}
		idx += numCubing[i];
		TopPrint();
	}

	return 0;
}