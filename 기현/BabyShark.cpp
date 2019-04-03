#include <iostream>
#include <queue>
#include <climits>
using namespace std;
int len;
int result = 0;//결과 값
int weight = 2;//아기상어의 무게

typedef struct {//위치
	int y, x;
}location;

typedef struct {//위치 + 이동 횟수
	location point;
	int cnt;
}mv;

queue<mv> q;

void print(int map[][21]) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void copyMap(int copy[][21], int origin[][21]) {//맵 카피
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			copy[i][j] = origin[i][j];
		}
	}
}

location dir[4] = { {-1,0}, {0,-1}, {0,1}, {1,0} };//방향 각각 북 1순위, 서쪽 2순위, 동쪽 3순위, 남쪽 4순위

void BFS(int map[][21], location start){
	int EatCnt = 0;//먹은 횟수 카운트
	int limit;//한도 저장
	bool finalFlag = true;
	bool BFSfinishFlag = false;


	vector<mv> candidate;//
	location savePoint = start;

	while (finalFlag) {
		limit = INT_MAX;//한도 이동 수 
		int copy[21][21];
		copyMap(copy, map);//copy에 bfs 적용시키기 위해 값을 옮긴다
		//print(copy);
		while (1) {
			BFSfinishFlag = false;
			if (q.empty()) {//만약 움직일 곳이 없다면 아예 종료
				finalFlag = false;
				break;
			}
			mv s = q.front();

			if (s.cnt > limit) {//만약 한도 이동보다 커지면 할 것은 다 했기 때문에 다음 단계로 넘어간다
				BFSfinishFlag = true;
				break;
			}

			q.pop();

			for (int i = 0; i < 4; i++) {//4개의 방향으로 움직인다
				/*방향 이동한 것을 tmp에 저장*/
				mv tmp;//이동한 위치 나타내는 struct
				tmp.point.y = s.point.y + dir[i].y;
				tmp.point.x = s.point.x + dir[i].x;
				tmp.cnt = s.cnt;
				int now = copy[tmp.point.y][tmp.point.x];//현재 위치
				if (tmp.point.y >= 0 && tmp.point.y < len && tmp.point.x >= 0 && tmp.point.x < len) {//만약 맵 범위를 벗어나지 않는다면
					if (now == 0 || now == weight) {//만약 이동할 수 있다면
						tmp.cnt++;
						copy[tmp.point.y][tmp.point.x] = INT_MAX;
						q.push(tmp);
					}
					else if (now < weight) {//먹을 수 있는 물고기를 발견했다면
						limit = tmp.cnt;//한도를 cnt로 구분
						tmp.cnt++;
						candidate.push_back(tmp);//후보군에 point 삽입
						copy[tmp.point.y][tmp.point.x] = INT_MAX;
						q.push(tmp);
					}
				}
			}
		}
		if (BFSfinishFlag == true) {//만약 bfs를 탈출했다면
			mv best;
			mv challenger;
			while (!q.empty()) {//다 비울때까지 반복
				q.pop();
			}

			best = candidate[0];
			for (vector<mv>::size_type i = 1; i < candidate.size(); i++) {//candidate 비교해서 가장 우선시 되는 먹이 찾기
				challenger = candidate[i];
				if (best.point.y > challenger.point.y || ((best.point.y == challenger.point.y) && (best.point.x > challenger.point.x))) {
					best = challenger;
				}
			}
			candidate.clear();//청소

			EatCnt++;
			if (EatCnt == weight) {//같아지면 상어의 무게가 늘어난다.
				weight++;
				EatCnt = 0;
			}
			result = result + best.cnt;//결과 값에 cnt 값을 더한다
			best.cnt = 0;//값 초기화

			//map에 먹은 곳을 상어 위치로 바꾸고 원래 상어가 있었던 곳을 0으로 교체
			map[savePoint.y][savePoint.x] = 0;
			map[best.point.y][best.point.x] = 9;
			savePoint = best.point;

			/*print(map);
			cout << "Middle Result: " << result << endl;
			cout << "Weight: " << weight << endl;
			cout << "========================" << endl;*/

			q.push(best);
		}
	}
}

int main() {
	int map[21][21];
	
	location shark;
	mv start;

	cin >> len;

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (map[i][j] == 9) {
				shark.y = i;
				shark.x = j;
			}
		}
	}
	
	start.cnt = 0;
	start.point = shark;
	q.push(start);
	
	BFS(map, shark);
	
	cout << result << endl;

	return 0;
}