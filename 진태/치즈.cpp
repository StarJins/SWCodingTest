#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int map[101][101];
int visited[101][101];
int n, m;
int ans1 = 0, ans2;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int main() {
	cin >> n >> m;
	
	int numOfCheese = 0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin >> map[i][j];
			if(map[i][j] == 1) {
				numOfCheese++;
			}
		}
	}
	
	int cnt = 0, tmp;
	while(true) {
		tmp = 0;
		queue<pair<int, int> > q;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				visited[i][j] = 0;
			}
		}
				
		q.push(make_pair(0, 0));
		visited[0][0] = 1;
		
		while(!q.empty()) {
			pair<int, int> cur = q.front(); q.pop();
			int y = cur.first;
			int x = cur.second;
			
			for(int i=0;i<4;i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				
				if(0<=ny && ny<n && 0<=nx && nx<m) {
					if(visited[ny][nx] == 0) {
						if(map[ny][nx] == 0) {
							q.push(make_pair(ny, nx));
						}
						
						if(map[ny][nx] == 1) {
							map[ny][nx] = 0;
							cnt++;
							tmp++;
						}
						visited[ny][nx] = 1;
					}
				}
			}
		}
		ans1++;
		ans2 = tmp;
		
		if(numOfCheese == cnt) break;
	}
	cout << ans1 << endl << ans2;
	return 0;
}