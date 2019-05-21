#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;

typedef struct {
	int m;
	int n;
	int sec;
}virusInfo;

pair<int, int> dir[4] = { {1,0}, {-1,0}, {0,1},{0,-1} };

int e;
int labMap[50][50];
int saveMap[50][50];
int minNum = INT_MAX;
int cnt = 0;
int vNum;
bool visited[10];

pair<int, int> c[10];
queue<virusInfo, list<virusInfo>> q;

void printMap() {
	int i, j;
	for (i = 0; i < e; i++) {
		for (j = 0; j < e; j++) {
			cout << saveMap[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
}

void copyMap(int copy[][50], int origin[][50]) {
	int i, j;
	for (i = 0; i < e; i++) {
		for (j = 0; j < e; j++) {
			copy[i][j] = origin[i][j];
		}
	}
}

void spread() {
	int i, j;
	int m, n;
	int y, x;
	int noVirus = 0;
	int addVirus = 0;
	int time;
	virusInfo pushVirus;
	//cout << "here!" << endl;

	
	copyMap(saveMap, labMap);
	for (i = 0; i < cnt; i++) {
		if (visited[i]) {
			saveMap[c[i].first][c[i].second] = 9;
			pushVirus.m = c[i].first;
			pushVirus.n = c[i].second;
			pushVirus.sec = 0;
			q.push(pushVirus);
		}
	}

	//printMap();

	for (i = 0; i < e; i++) {
		for (j = 0; j < e; j++) {
			if (saveMap[i][j] == 0)
				noVirus++;
		}
	}



	while (!q.empty()) {
		virusInfo active = q.front();
		q.pop();

		m = active.m;
		n = active.n;
		time = active.sec;
		if (time >= minNum) {
			while (!q.empty()) {
				q.pop();
			}
			break;
		}

		for (i = 0; i < 4; i++) {
			y = m + dir[i].first;
			x = n + dir[i].second;

			if (x >= 0 && x < e && y >= 0 && y < e) {
				if (saveMap[y][x] == 0) {
					pushVirus.m = y;
					pushVirus.n = x;
					pushVirus.sec = time + 1;
					addVirus++;
					saveMap[y][x] = 9;
					q.push(pushVirus);
				}
				else if (saveMap[y][x] == 2) {
					if (addVirus == noVirus) {
						break;
					}
					pushVirus.m = y;
					pushVirus.n = x;
					pushVirus.sec = time + 1;
					saveMap[y][x] = 9;
					q.push(pushVirus);
				}
			}
		}
		
		
	}

	
	
	if (addVirus == noVirus) {
		//printMap();
		minNum = min(minNum, time);
		//cout << minNum << endl;
		//cout << "=====================================================" <<endl;
	}
}

void select(int k, int start) {//dfs
	int i;
	
	if (k == vNum) {//개수가 맞으면
		spread();
		return;
	}

	for (i = start; i < cnt; i++) {
		//개수 추가
		visited[i] = true;
		select(k + 1, i + 1);
		//백트래킹
		visited[i] = false;
	}
}



int main() {
	int i, j;
	cin >> e >> vNum;

	//입력, 활성 바이러스면 저장
	for (i = 0; i < e; i++) {
		for (j = 0; j < e; j++) {
			cin >> labMap[i][j];
			if (labMap[i][j] == 2) {
				c[cnt].first = i;
				c[cnt].second = j;
				cnt++;
			}
		}
	}

	select(0, 0);

	if (minNum == INT_MAX) {
		cout << -1 << endl;
	}
	else {
		cout << minNum << endl;
	}

	return 0;

}