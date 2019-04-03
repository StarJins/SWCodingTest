#include <iostream>
#include <queue>
#include <climits>
using namespace std;
int len;
int result = 0;//��� ��
int weight = 2;//�Ʊ����� ����

typedef struct {//��ġ
	int y, x;
}location;

typedef struct {//��ġ + �̵� Ƚ��
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

void copyMap(int copy[][21], int origin[][21]) {//�� ī��
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			copy[i][j] = origin[i][j];
		}
	}
}

location dir[4] = { {-1,0}, {0,-1}, {0,1}, {1,0} };//���� ���� �� 1����, ���� 2����, ���� 3����, ���� 4����

void BFS(int map[][21], location start){
	int EatCnt = 0;//���� Ƚ�� ī��Ʈ
	int limit;//�ѵ� ����
	bool finalFlag = true;
	bool BFSfinishFlag = false;


	vector<mv> candidate;//
	location savePoint = start;

	while (finalFlag) {
		limit = INT_MAX;//�ѵ� �̵� �� 
		int copy[21][21];
		copyMap(copy, map);//copy�� bfs �����Ű�� ���� ���� �ű��
		//print(copy);
		while (1) {
			BFSfinishFlag = false;
			if (q.empty()) {//���� ������ ���� ���ٸ� �ƿ� ����
				finalFlag = false;
				break;
			}
			mv s = q.front();

			if (s.cnt > limit) {//���� �ѵ� �̵����� Ŀ���� �� ���� �� �߱� ������ ���� �ܰ�� �Ѿ��
				BFSfinishFlag = true;
				break;
			}

			q.pop();

			for (int i = 0; i < 4; i++) {//4���� �������� �����δ�
				/*���� �̵��� ���� tmp�� ����*/
				mv tmp;//�̵��� ��ġ ��Ÿ���� struct
				tmp.point.y = s.point.y + dir[i].y;
				tmp.point.x = s.point.x + dir[i].x;
				tmp.cnt = s.cnt;
				int now = copy[tmp.point.y][tmp.point.x];//���� ��ġ
				if (tmp.point.y >= 0 && tmp.point.y < len && tmp.point.x >= 0 && tmp.point.x < len) {//���� �� ������ ����� �ʴ´ٸ�
					if (now == 0 || now == weight) {//���� �̵��� �� �ִٸ�
						tmp.cnt++;
						copy[tmp.point.y][tmp.point.x] = INT_MAX;
						q.push(tmp);
					}
					else if (now < weight) {//���� �� �ִ� ����⸦ �߰��ߴٸ�
						limit = tmp.cnt;//�ѵ��� cnt�� ����
						tmp.cnt++;
						candidate.push_back(tmp);//�ĺ����� point ����
						copy[tmp.point.y][tmp.point.x] = INT_MAX;
						q.push(tmp);
					}
				}
			}
		}
		if (BFSfinishFlag == true) {//���� bfs�� Ż���ߴٸ�
			mv best;
			mv challenger;
			while (!q.empty()) {//�� ��ﶧ���� �ݺ�
				q.pop();
			}

			best = candidate[0];
			for (vector<mv>::size_type i = 1; i < candidate.size(); i++) {//candidate ���ؼ� ���� �켱�� �Ǵ� ���� ã��
				challenger = candidate[i];
				if (best.point.y > challenger.point.y || ((best.point.y == challenger.point.y) && (best.point.x > challenger.point.x))) {
					best = challenger;
				}
			}
			candidate.clear();//û��

			EatCnt++;
			if (EatCnt == weight) {//�������� ����� ���԰� �þ��.
				weight++;
				EatCnt = 0;
			}
			result = result + best.cnt;//��� ���� cnt ���� ���Ѵ�
			best.cnt = 0;//�� �ʱ�ȭ

			//map�� ���� ���� ��� ��ġ�� �ٲٰ� ���� �� �־��� ���� 0���� ��ü
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