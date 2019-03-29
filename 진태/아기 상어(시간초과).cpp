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

	// �ʱ� �����ġ ���ϱ�
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
				foodList.push_back(make_pair(i, j));	// ���� ��ġ ����
}

void BFS() {
	int foodCount = foodList.size();	// ����ȭ

	// BFS�� ���� �ʱ�ȭ
	queue<element> q;
	q.push({ y, x, sec });
	visited[y][x] = sec;

	while (!q.empty()) {	// visited�� �� �� �ִ� �ִܰŸ� ���� ǥ��
		struct element cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];

			if (0 <= ny && ny < n && 0 <= nx && nx < n) {
				if (map[ny][nx] <= babySize) {
					if (visited[ny][nx] > cur.cnt + 1) {	// ����Ŭ ���� ����
						q.push({ ny, nx, cur.cnt + 1 });
						visited[ny][nx] = cur.cnt + 1;

						if (find(foodList.begin(), foodList.end(), make_pair(ny, nx)) != foodList.end()) {	// ���� ����� ������ ���̰� �ִ� �����̶��
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
					if (map[ny][nx] > babySize) {	// ��
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
					if (map[ny][nx] > babySize) {	// ��
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
					if (map[ny][nx] > babySize) {	// ��
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
		if(visited[ty][tx] > visited[foodList[i].first][foodList[i].second]) {	// ���� ������
			ty = foodList[i].first;
			tx = foodList[i].second;
		}
		else if (visited[ty][tx] == visited[foodList[i].first][foodList[i].second]) {	// �Ÿ� ������ ���� ������
			if (ty > foodList[i].first) {
				ty = foodList[i].first;
				tx = foodList[i].second;
			}
			else if (ty == foodList[i].first) {	// �װŸ����� ������ ���� ���ʰ�
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
	// ��� ��ġ �ٲٱ�
	map[y][x] = 0;
	y = curFood.first;
	x = curFood.second;
	map[y][x] = 9;

	sec = visited[y][x];
	needs--;
	foodList.erase(find(foodList.begin(), foodList.end(), curFood));
}

int main() {
	Init();	// �Է� �� ��� �ʱ� ��ġ Ž��

	while (true) {
		VisitedInit();		// �ּҰŸ� ǥ���ϴ� ��� �ʱ�ȭ
		CheckFoodLocate();	// ���� �� �ִ� ��� �� ����
		if (foodList.size() == 0)		// ������ ������ �ٷ� ����
			break;

//		BFS();
		CalDist();

		pair<int, int> curFood = FindClosedFood();
		Eat(curFood);

		if (needs == 0) {	// ũ�� Ű���
			babySize++;
			needs = babySize;	// �Ծ�� �ϴ� ��� ��
		}
		else if (foodList.size() == 0 && needs != 0 && needs != babySize)	// ���̸� �� �Ծ��µ� ������ �� �� ���
			break;
	}

	cout << sec;
	return 0;
}