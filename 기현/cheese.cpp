#include <iostream>
#include <algorithm>
using namespace std;

int cheeseMap[100][100];
int SaveMap[100][100];
int r, c;

bool flag = false;
int rem = 0;


void print(int arr[100][100]) {
	int i, j;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void copyMap(int copy[100][100], int origin[100][100]) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			copy[i][j] = origin[i][j];
		}
	}
}

void flood_fill(int m, int n) {
	if (SaveMap[m][n] == 1) {
		if(flag == false)
			flag = true;
		SaveMap[m][n] = 2;
		rem++;
	}
	else if(SaveMap[m][n] == 0){
		SaveMap[m][n] = -1;
		if(m > 0)
			flood_fill(m - 1, n);
		if(m < r-1)
			flood_fill(m + 1, n);
		if(n > 0)
			flood_fill(m, n - 1);
		if(n < c-1)
			flood_fill(m, n + 1);
	}

}

int main() {

	int i, j;
	int cnt = 0;
	int x = 0;
	int y = 0;
	int resultRem;

	cin >> r >> c;

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			cin >> cheeseMap[i][j];
		}
	}

	flag = true;
	while (flag) {
		
		rem = 0;
		flag = false;;

		copyMap(SaveMap, cheeseMap);
		//print(SaveMap);
		flood_fill(x, y);
		if (flag) {
			cnt++;
			resultRem = rem;
		}
		//print(SaveMap);
		for (i = 0; i < r; i++) {
			for (j = 0; j < c; j++) {
				if (SaveMap[i][j] == 2) {
					cheeseMap[i][j] = 0;
				}
			}
		}
		//print(cheeseMap);
		cout << "===============================" << endl;
	}

	cout << cnt << endl;
	cout << resultRem << endl;

	return 0;
}