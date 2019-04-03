#include <iostream>
#include <string>
using namespace std;

char SpinCmd[1000][2];

char upS[3][3];
char downS[3][3];
char frontS[3][3];
char backS[3][3];
char leftS[3][3];
char rightS[3][3];

void initializeCube() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			upS[i][j] = 'w';
			downS[i][j] = 'y';
			frontS[i][j] = 'r';
			backS[i][j] = 'o';
			leftS[i][j] = 'g';
			rightS[i][j] = 'b';
		}
	}
}

void spin(char &n1, char &n2, char &n3, char &n4) {
	char tmp = n1;
	n1 = n2;
	n2 = n3;
	n3 = n4;
	n4 = tmp;
}

void cubing(int cmd) {
	for (int i = 0; i < cmd; i++) {
		switch (SpinCmd[i][0]) {
		case 'U':
			if (SpinCmd[i][1] = '+') {
				for(int j=0; j<3; j++)
					spin(backS[0][j], rightS[0][j], frontS[0][2-j], leftS[0][2-j]);
			}
			else {
				for (int j = 0; j < 3; j++)
					spin(backS[0][j], leftS[0][j], frontS[0][2-j], rightS[0][2-j]);
			}
			break;
		case 'D':
			if (SpinCmd[i][1] = '+') {
				for (int j = 0; j < 3; j++)
					spin(backS[2][j], rightS[2][j], frontS[2][2-j], leftS[2][2-j]);
			}
			else {
				for (int j = 0; j < 3; j++)
					spin(backS[2][j], leftS[2][j], frontS[2][2-j], rightS[2][2-j]);
			}
			break;
		case 'B':
			if (SpinCmd[i][1] = '+') {
				for (int j = 0; j < 3; j++)
					spin(upS[2][j], rightS[j][2], downS[2][2-j], leftS[2-j][2]);
			}
			else {
				for (int j = 0; j < 3; j++)
					spin(upS[2][j], leftS[j][2], downS[2][2-j], rightS[2-j][2]);
			}
			break;
		case 'F':
			if (SpinCmd[i][1] = '+') {
				for (int j = 0; j < 3; j++)
					spin(upS[0][j], rightS[j][0], downS[0][2 - j], leftS[2 - j][0]);
			}
			else {
				for (int j = 0; j < 3; j++)
					spin(upS[0][j], leftS[j][0], downS[0][2 - j], rightS[2 - j][0]);
			}
			break;
		case 'L':
			if (SpinCmd[i][1] = '+') {
				for (int j = 0; j < 3; j++)
					spin(upS[j][0], frontS[j][0], downS[2 - j][0], backS[2 - j][0]);
			}
			else {
				for (int j = 0; j < 3; j++)
					spin(upS[j][0], backS[j][0], downS[2 - j][0], frontS[2 - j][0]);
			}
			break;
		case 'R':
			if (SpinCmd[i][1] = '+') {
				for (int j = 0; j < 3; j++)
					spin(upS[j][2], frontS[j][2], downS[2 - j][2], backS[2 - j][2]);
			}
			else {
				for (int j = 0; j < 3; j++)
					spin(upS[j][2], backS[j][2], downS[2 - j][2], frontS[2 - j][2]);
			}
			break;
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << upS[i][j];
			}
			cout << endl;
		}
		cout<<endl;
	}

	/*for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << upS[i][j];
		}
		cout << endl;
	}*/
}

int main() {
	
	int cnt;
	int cmd;

	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		initializeCube();
		cin >> cmd;
		for (int j = 0; j < cmd; j++) {
			cin >> SpinCmd[j];
		}
		cubing(cmd);
	}
	

	return 0;
}