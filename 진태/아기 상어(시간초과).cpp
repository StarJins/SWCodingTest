#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n;
int map[21][21];
int visited[21][21];

int sec = 0;
int babySize = 2;
int y = 0, x = 0;
int needs = babySize;
vector<pair<int, int> > foodList;

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
enum {UP, DOWN, LEFT, RIGHT};

struct element {
	int y, x, cnt;
};

void Init() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	// 초기 상어위치 구하기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 9) {
				y = i;
				x = j;
				return;
			}
		}
	}
}

void VisitedInit() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			visited[i][j] = 987654321;
}

void CheckFoodLocate() {
	foodList.clear();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (map[i][j] < babySize && map[i][j] != 0)
				foodList.push_back(make_pair(i, j));	// 먹이 위치 저장
}

void BFS() {
	int foodCount = foodList.size();	// 최적화

	// BFS를 위한 초기화
	queue<element> q;
	q.push({ y, x, sec });
	visited[y][x] = sec;

	while (!q.empty()) {	// visited에 갈 수 있는 최단거리 전부 표시
		struct element cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];

			if (0 <= ny && ny < n && 0 <= nx && nx < n) {
				if (map[ny][nx] <= babySize) {
					if (visited[ny][nx] > cur.cnt + 1) {	// 싸이클 방지 조건
						q.push({ ny, nx, cur.cnt + 1 });
						visited[ny][nx] = cur.cnt + 1;

						if (find(foodList.begin(), foodList.end(), make_pair(ny, nx)) != foodList.end()) {	// 현재 계산한 자점이 먹이가 있는 지점이라면
							foodCount--;
							if (foodCount == 0)
								return;
						}
					}
				}
			}
		}
	}
}

void CalDist() {
	for (int l = 0; l < foodList.size(); l++) {
		pair<int, int> curFood = foodList[l];
		int ty = curFood.first;
		int tx = curFood.second;
		
		int ny = y;
		int nx = x;

		int cnt = 0;

		if (ty - y > 0) {
			if (tx - x > 0) {
				while (true) {
					if (ny == ty && nx == tx) {
						visited[ty][tx] = min(visited[ty][tx], cnt);
						break;
					}

					int i = RIGHT;
					ny += dy[i], nx += dx[i];
					cnt++;
					if (map[ny][nx] > babySize) {	// 벽
						ny -= dy[i], nx -= dx[i];
						cnt--;
						i = (i == RIGHT) ? UP : RIGHT;
					}
				}
			}
			else if (tx - x == 0) {
				while (true) {
					if (ny == ty && nx == tx) {
						visited[ty][tx] = min(visited[ty][tx], cnt);
						break;
					}

					int i = RIGHT;
					ny += dy[i], nx += dx[i];
					cnt++;
					if (map[ny][nx] > babySize) {	// 벽
						ny -= dy[i], nx -= dx[i];
						cnt--;//????????????????????
					}
				}
			}
			else {
				while (true) {
					if (ny == ty && nx == tx) {
						visited[ty][tx] = min(visited[ty][tx], cnt);
						break;
					}

					int i = RIGHT;
					ny += dy[i], nx += dx[i];
					cnt++;
					if (map[ny][nx] > babySize) {	// 벽
						ny -= dy[i], nx -= dx[i];
						cnt--;
						i = (i == RIGHT) ? UP : RIGHT;
					}
				}
			}
		}
		else if (ty - y == 0) {
			if (tx - x > 0) {

			}
			else if (tx - x == 0) {

			}
			else {

			}
		}
		else {
			if (tx - x > 0) {

			}
			else if (tx - x == 0) {

			}
			else {

			}
		}
	}
}

pair<int, int> FindClosedFood() {
	int ty = foodList[0].first;
	int tx = foodList[0].second;

	for (int i = 1; i < foodList.size(); i++) {
		if(visited[ty][tx] > visited[foodList[i].first][foodList[i].second]) {	// 가장 가까운거
			ty = foodList[i].first;
			tx = foodList[i].second;
		}
		else if (visited[ty][tx] == visited[foodList[i].first][foodList[i].second]) {	// 거리 같으면 가장 위에거
			if (ty > foodList[i].first) {
				ty = foodList[i].first;
				tx = foodList[i].second;
			}
			else if (ty == foodList[i].first) {	// 그거마저도 같으면 가장 왼쪽거
				if (tx > foodList[i].second) {
					ty = foodList[i].first;
					tx = foodList[i].second;
				}
			}
		}
	}
	return make_pair(ty, tx);
}

void Eat(pair<int, int> curFood) {
	// 상어 위치 바꾸기
	map[y][x] = 0;
	y = curFood.first;
	x = curFood.second;
	map[y][x] = 9;

	sec = visited[y][x];
	needs--;
	foodList.erase(find(foodList.begin(), foodList.end(), curFood));
}

int main() {
	Init();	// 입력 및 상어 초기 위치 탐색

	while (true) {
		VisitedInit();		// 최소거리 표현하는 행렬 초기화
		CheckFoodLocate();	// 먹을 수 있는 상어 수 조사
		if (foodList.size() == 0)		// 먹을게 없으면 바로 종료
			break;

//		BFS();
		CalDist();

		pair<int, int> curFood = FindClosedFood();
		Eat(curFood);

		if (needs == 0) {	// 크기 키우기
			babySize++;
			needs = babySize;	// 먹어야 하는 상어 수
		}
		else if (foodList.size() == 0 && needs != 0 && needs != babySize)	// 먹이를 다 먹었는데 성장을 못 한 경우
			break;
	}

	cout << sec;
	return 0;
}