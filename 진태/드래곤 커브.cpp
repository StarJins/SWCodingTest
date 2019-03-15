#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int map[101][101];
int n;
int x, y, d, g;
int ans = 0;

stack<int> dragon;
stack<int> cal;
stack<int> tmp1;
queue<int> tmp2;


int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };

int main() {

	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			map[i][j] = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &x, &y, &d, &g);

		// Solve
		/* 
		���⼭ queue�� stack���� ����� �� �����ϰ� �ߴµ� �׳� vector�Ἥ �ε��� �� �����ϸ� �� ª�� �� �Ű���.
		�巡�� Ŀ�� �׸��� ����

		������ ���ڷ� ��Ÿ����
		0:Right, 1:Up, 2:Left, 3:Down

		0���� �����Ѵٰ� �����ϸ� ���������� ���� �̷��� �׷�����
		0����: 0
		1����: 0 1
		2����: 0 1 2 1
		3����: 0 1 2 1 2 3 2 1
		4����: 0 1 2 1 2 3 2 1 2 3 0 3 2 3 2 1

		���� ���뿡�� �������� (x + 1) % 4 ���� ��, �����ϸ� �ȴ�.
		
		���� ���� ����� ��, ���������κ��� ���ʴ�� �׸��� �ϼ�
		*/
		map[x][y] = 1;	// ������ ǥ��
		dragon.push(d);

		// �巡�� Ŀ�� ���� �����
		for (int j = 0; j < g; j++) {
			
			while (!dragon.empty()) {
				int value = dragon.top();
				dragon.pop();

				tmp1.push(value);

				value = (value + 1) % 4;
				tmp2.push(value);
			}

			// ���� ����
			while (!tmp1.empty()) {
				dragon.push(tmp1.top());
				tmp1.pop();
			}
			while (!tmp2.empty()) {
				dragon.push(tmp2.front());
				tmp2.pop();
			}
		}
		while (!dragon.empty()) {
			cal.push(dragon.top());
			dragon.pop();
		}

		// ��ǥ ���
		while (!cal.empty()) {
			int index = cal.top();
			cal.pop();
		
			x = x + dx[index];
			y = y + dy[index];

			map[x][y] = 1;
		}
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j] == 1 && map[i + 1][j + 1] == 1)
				ans++;
		}
	}

	printf("%d", ans);
	return 0;
}