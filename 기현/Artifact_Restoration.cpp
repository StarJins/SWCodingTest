#include <iostream>
using namespace std;

int used[51][51];
int arr[51][51];
pair<int, int> point[2500];
int m1cnt = 0;
bool flag = false;

int n, m, k;

void print(int a[][51]) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			cout << a[i][j] << '\t';
		}
		cout << endl;
	}
}

void fillUsedArr() {//��� 1�� ������ �� ĭ�� �� �� ���Ǵ��� ����ϴ� ĭ 
	int i, j;
	int a;
	int midN = n / 2; 
	int midM = m / 2;
	int down;

	used[0][1] = used[0][m] = m;
	used[1][0] = used[n][0] = n;
	//cout << midN <<  ' ' << midM << endl;

	down = n;
	a = 2;
	while (a <= midN) {
		down = down - 2;
		used[a][0] = used[a - 1][0] + down;
		used[n + 1 - a][0] = used[n + 2 - a][0] + down;
		a++;
	}
	if (n % 2 == 1) {
		used[a][0] = used[a - 1][0] + 1;
	}

	down = m;
	a = 2;
	while (a <= midM) {
		down = down - 2;
		used[0][a] = used[0][a - 1] + down;
		used[0][m + 1 - a] = used[0][m + 2 - a] + down;
		a++;
	}
	if (m % 2 == 1) {
		used[0][a] = used[0][a - 1] + 1;
	}

	

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			used[i][j] = (used[i][0] * used[0][j]) % k;
		}
	}
}

void dfs(int a, int ar[][51], int s) {//dfs �ݺ� ������ �ϳ� �߰��ϸ� �ٷ� Ż��, flag�� ����.
	int y, x;

	if (s % k == 0) {//������ �����ϴ� ���� �߰� ��
		//cout << s << ", " << k << endl;
		while (a < m1cnt) {
			//cout << a << endl;
			y = point[a].first;
			x = point[a].second;
			ar[y][x] = 0;
			a++;
		}
		cout << 1 << endl;
		print(ar);
		flag = true;
		return;
	}
	else if (a == m1cnt) {//�ҵ���� ������ ���� ��
		return;
	}
	if (flag) {//�̹� �ϳ� ã���� ��
		return;
	}
	
	y = point[a].first;
	x = point[a].second;

	ar[y][x] = 1;
	dfs(a + 1, ar, s + used[y][x]);
	ar[y][x] = 0;
	dfs(a + 1, ar, s);
}


int main() {
	
	//int midN, midM;
	int i, j;
	int sum = 0;
	
	
	
	cin >> n >> m >> k;

	fillUsedArr();
	//print(used);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)//�̸� �� ����
				sum = sum + used[i][j];
			else if (arr[i][j] == -1) {//-1�̸� ���� ǥ�� ����
				point[m1cnt].first = i;
				point[m1cnt++].second = j;
			}
		}
	}
	//cout << "m1cnt: " << m1cnt << endl;
	
	sum = sum % k;
	//cout << "first sum: " << sum << endl;

	dfs(0, arr, sum);

	if (!flag)//���� ������ �� ã������ -1 ���
		cout << -1 << endl;

	return 0;
}