#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define MAX_MAP 15

typedef struct {
	int r, c, life;
} Enermy;

typedef struct {
	int r, c;
} Archer;

int n, m, d;
int map[MAX_MAP + 5][MAX_MAP + 5];
vector<Enermy> enermies;
vector<Archer> archers;
int ans;

bool comp(Enermy &a, Enermy &b) {
	if (a.c > b.c) return true;
	else return false;
}

void Init() {
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) enermies.push_back({ i, j, 1 });
		}
	}
	sort(enermies.begin(), enermies.end(), comp);

	for (int i = 0; i < m; i++)
		map[n][i] = 0;

	ans = 0;
}

int Run() {
	// save position of archers
	for (int i = 0; i < m; i++)
		if (map[n][i] == 1) archers.push_back({ n, i });

	// save original enermies info
	vector<Enermy> saveEnermies;
	for (int i = 0; i < enermies.size(); i++)
		saveEnermies.push_back(enermies[i]);

	// game start
	int killScore = 0;
	while (enermies.size() > 0) {
		// 1. archers attack
		for (int i = 0; i < archers.size(); i++) {
			int minIdx = -1, minDist = 987654321;
			for (int j = 0; j < enermies.size(); j++) {
				int dist = abs(archers[i].r - enermies[j].r) + abs(archers[i].c - enermies[j].c);
				if (dist <= d) {
					if (dist <= minDist) {
						minIdx = j;
						minDist = dist;
					}
				}
			}
			if(minIdx != -1) enermies[minIdx].life--;
		}
		for (int i = enermies.size() - 1; i >= 0; i--) {
			if (enermies[i].life < 1) {
				enermies.erase(enermies.begin() + i);
				killScore++;
			}
		}

		// 2. move enermies
		for (int i = enermies.size() - 1; i >= 0; i--) {
			enermies[i].r++;
			if (enermies[i].r >= n) enermies.erase(enermies.begin() + i);
		}
	}

	// clear archers info
	archers.clear();

	// recover enermies info
	enermies.clear();
	for (int i = 0; i < saveEnermies.size(); i++)
		enermies.push_back(saveEnermies[i]);

	return killScore;
}

void DFS(int cur, int cnt) {
	if (cnt == 3) {
		int killScore = Run();
		ans = max(killScore, ans);
		return;
	}

	for (int i = cur; i < m; i++) {
		map[n][i] = 1;
		DFS(i + 1, cnt + 1);
		map[n][i] = 0;
	}
}

int main() {
	Init();
	DFS(0, 0);

	cout << ans << endl;
	return 0;
}