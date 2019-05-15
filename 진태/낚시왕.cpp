#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct {
	int r, c, s, d, z;
} Sharke;

vector<Sharke> sharkes;
int r, c, m;
int person = 0;
int ans;

int dr[] = { 0, -1, 1, 0, 0 };
int dc[] = { 0, 0, 0, 1, -1 };

void Init() {
	cin >> r >> c >> m;
	for (int i = 0; i < m; i++) {
		Sharke s;
		cin >> s.r >> s.c >> s.s >> s.d >> s.z;
		sharkes.push_back(s);
	}
}

bool cmp(Sharke a, Sharke b) {
	if (a.c != b.c)
		return a.c < b.c;
	else
		return a.r < b.r;
}

void Catch() {
	sort(sharkes.begin(), sharkes.end(), cmp);

	for (int i = 0; i < sharkes.size(); i++) {
		if (person < sharkes[i].c)
			return;

		if (person == sharkes[i].c) {
			ans += sharkes[i].z;
			sharkes.erase(sharkes.begin() + i);
			return;
		}
	}
}

void SharkesMove() {
	for (int i = 0; i < sharkes.size(); i++) {
		Sharke &cur = sharkes[i];
		for (int j = 0; j < cur.s; j++) {
			cur.r += dr[cur.d];
			cur.c += dc[cur.d];

			if (cur.r < 1) {
				cur.d = 2;
				cur.r = 2;
			}
			else if (cur.r > r) {
				cur.d = 1;
				cur.r = r - 1;
			}
			else if (cur.c < 1) {
				cur.d = 3;
				cur.c = 2;
			}
			else if (cur.c > c) {
				cur.d = 4;
				cur.c = c - 1;
			}
		}
	}

	sort(sharkes.begin(), sharkes.end(), cmp);
	for (int i = 0; i < int(sharkes.size() - 1); i++) {
		Sharke &cur = sharkes[i];
		Sharke &next = sharkes[i + 1];

		if ((cur.r == next.r) && (cur.c == next.c)) {
			if (cur.z > next.z) sharkes.erase(sharkes.begin() + i + 1);
			else sharkes.erase(sharkes.begin() + i);
			i--;
		}
	}
}

int main() {
	Init();

	if (sharkes.size() != 0) {
		for (int i = 0; i <= c; i++) {
			person++;
			Catch();
			SharkesMove();
		}
	}

	cout << ans;
	return 0;
}