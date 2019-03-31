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
			visited[i][j] = -1;
}

void BFS() {
	// BFS를 위한 초기화
	int shortest = 987654321;
	int dist = 0;
	foodList.clear();

	queue<element> q;
	q.push({ y, x, dist });
	visited[y][x] = dist;

	while (!q.empty()) {	// visited에 갈 수 있는 최단거리 전부 표시
		struct element cur = q.front(); q.pop();

		if (cur.cnt > shortest)	// 가장 가까운 먹이 라운드 다 구했으면 종료
			return;

		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];

			if (0 <= ny && ny < n && 0 <= nx && nx < n) {
				if (map[ny][nx] <= babySize && visited[ny][nx] == -1) {	// 지나갈 수 있는 곳이면 큐에 삽입
					q.push({ ny, nx, cur.cnt + 1 });
					visited[ny][nx] = cur.cnt + 1;

					if (map[ny][nx] < babySize && map[ny][nx] != 0) {	// 먹이라면 추가
						foodList.push_back(make_pair(ny, nx));

						if (shortest == 987654321)	// 라운드 제한 걸기
							shortest = cur.cnt + 1;
					}
				}
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

	sec += visited[y][x];
	needs--;
}

int main() {
	Init();							// 입력 및 상어 초기 위치 탐색

	while (true) {
		VisitedInit();				// 최소거리 표현하는 행렬 초기화
		
		BFS();						// 가장 가까운 먹이까지 최소거리 구하기
		if (foodList.size() == 0)	// 먹을게 없으면 바로 종료
			break;

		// 가장 가까운 먹이 찾아서 먹기
		pair<int, int> curFood = FindClosedFood();
		Eat(curFood);

		if (needs == 0) {			// 크기 키우기
			babySize++;
			needs = babySize;
		}
	}

	cout << sec;
	return 0;
}