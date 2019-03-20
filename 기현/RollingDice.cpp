#include <iostream>
#include <vector>
using namespace std;

bool OutCheck(int mdf, int arrlen) {
	if (mdf >= arrlen || mdf < 0)
		return false;
	else
		return true;
}

/*void PrintDice(int * dice) {
	cout << "상단: " << dice[0] << endl;
	cout << "앞쪽: " << dice[1] << endl;
	cout << "오른쪽: " << dice[2] << endl;
	cout << "뒤쪽: " << dice[3] << endl;
	cout << "왼쪽: " << dice[4] << endl;
	cout << "하단: " << dice[5] << endl;
}*/

void changeDice(int& below, int& map) {
	if (map == 0) {
		map = below;
	}
	else {
		below = map;
		map = 0;
	}
}

int main() {
	int M, N;
	int x, y;
	int cmd;
	int dir;
	int temp;
	int dice[6] = { 0,0,0,0,0,0 };

	cin >> N >> M >> x >> y >> cmd;
	
	vector<vector<int>>arr(N, vector<int>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;*/

	vector<int> cmdArr(cmd);

	
	for (int i = 0; i < cmd; i++) {
		cin >> dir;
		cmdArr[i] = dir;
	}
		
	for(int i=0; i<cmd; i++){
		switch (cmdArr[i]) {
			case 1:
				if (OutCheck(y + 1, M)) {
					temp = dice[0];
					dice[0] = dice[4];
					dice[4] = dice[5];
					dice[5] = dice[2];
					dice[2] = temp;

					changeDice(dice[5], arr[x][++y]);
					//PrintDice(dice);
					cout << dice[0] << endl;
				}
				break;
			case 2:
				if (OutCheck(y - 1, M)) {
					temp = dice[0];
					dice[0] = dice[2];
					dice[2] = dice[5];
					dice[5] = dice[4];
					dice[4] = temp;
					
					changeDice(dice[5], arr[x][--y]);
					//PrintDice(dice);
					cout << dice[0] << endl;
				}
				break;
			case 3:
				if (OutCheck(x - 1, N)) {
					temp = dice[0];
					dice[0] = dice[1];
					dice[1] = dice[5];
					dice[5] = dice[3];
					dice[3] = temp;
					changeDice(dice[5], arr[--x][y]);
					//PrintDice(dice);
					cout << dice[0] << endl;
				}
				break;
			case 4:
				if (OutCheck(x + 1, N)) {
					temp = dice[0];
					dice[0] = dice[3];
					dice[3] = dice[5];
					dice[5] = dice[1];
					dice[1] = temp;
					
					changeDice(dice[5], arr[++x][y]);
					//PrintDice(dice);
					cout << dice[0] << endl;
				}
				break;
		}
		/*for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << arr[i][j] << ' ';
			}
			cout << endl;
		}
		cout << "====================" << endl;*/
	}

	return 0;
}