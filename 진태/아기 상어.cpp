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
			visited[i][j] = -1;
}

void BFS() {
	// BFS�� ���� �ʱ�ȭ
	int shortest = 987654321;
	int dist = 0;
	foodList.clear();

	queue<element> q;
	q.push({ y, x, dist });
	visited[y][x] = dist;

	while (!q.empty()) {	// visited�� �� �� �ִ� �ִܰŸ� ���� ǥ��
		struct element cur = q.front(); q.pop();

		if (cur.cnt > shortest)	// ���� ����� ���� ���� �� �������� ����
			return;

		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];

			if (0 <= ny && ny < n && 0 <= nx && nx < n) {
				if (map[ny][nx] <= babySize && visited[ny][nx] == -1) {	// ������ �� �ִ� ���̸� ť�� ����
					q.push({ ny, nx, cur.cnt + 1 });
					visited[ny][nx] = cur.cnt + 1;

					if (map[ny][nx] < babySize && map[ny][nx] != 0) {	// ���̶�� �߰�
						foodList.push_back(make_pair(ny, nx));

						if (shortest == 987654321)	// ���� ���� �ɱ�
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

	sec += visited[y][x];
	needs--;
}

int main() {
	Init();							// �Է� �� ��� �ʱ� ��ġ Ž��

	while (true) {
		VisitedInit();				// �ּҰŸ� ǥ���ϴ� ��� �ʱ�ȭ
		
		BFS();						// ���� ����� ���̱��� �ּҰŸ� ���ϱ�
		if (foodList.size() == 0)	// ������ ������ �ٷ� ����
			break;

		// ���� ����� ���� ã�Ƽ� �Ա�
		pair<int, int> curFood = FindClosedFood();
		Eat(curFood);

		if (needs == 0) {			// ũ�� Ű���
			babySize++;
			needs = babySize;
		}
	}

	cout << sec;
	return 0;
}