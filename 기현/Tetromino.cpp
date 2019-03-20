#include <iostream>
#include <algorithm>
using namespace std;
int N,M;

typedef struct {
	int x, y;
}Direction;

Direction news[4] = { {1,0}, {-1,0}, {0, 1}, {0, -1} };
//Direction news[4] = { (1,0), (-1,0), (0, 1), (0, -1) };

int arr[501][501];
bool visited[501][501];

int DFS(int x, int y, int cnt) {//dfs 방식, 잘 익히도록 하자.
	if (cnt == 4) {//종료 조건
		return arr[x][y];
	}

	int sum = 0;
	
	for (int i = 0; i < 4; i++) {
		int nextX = x + news[i].x;
		int nextY = y + news[i].y;

		if (0 <= nextX && nextX < N && 0 <= nextY && nextY < M && !visited[nextX][nextY]){
			visited[nextX][nextY] = true;
			sum = max(sum, arr[x][y] + DFS(nextX, nextY, cnt + 1));
			visited[nextX][nextY] = false; 
		}
	}
	return sum;
}

int finger(int x, int y) {
	int result = 0;

	if (x >= 1 && y >= 1 && y < M - 1)//ㅗ
		result = max(result,arr[x][y] + arr[x][y+1] + arr[x][y-1] + arr[x+1][y]);
	if (y >= 1 && y < M - 1 && x < N - 1)//ㅜ
		result = max(result, arr[x][y] + arr[x][y+1] + arr[x][y-1] + arr[x-1][y]);
	if (x >= 1 && y < M - 1 && x < N - 1)// ㅏ
		result = max(result, arr[x][y] + arr[x + 1][y] + arr[x - 1][y] + arr[x][y + 1]);
	if (x >= 1 && y >= 1 && x < N - 1)//ㅓ
		result = max(result, arr[x][y] + arr[x + 1][y] + arr[x - 1][y] + arr[x][y - 1]);

	return result;
}

int main() {
	int result = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			visited[i][j] = true;
			result = max(result, DFS(i, j, 1));//dfs
			result = max(result, finger(i, j));
			visited[i][j] = false;
		}
	cout << result << endl;
	return 0;
}

