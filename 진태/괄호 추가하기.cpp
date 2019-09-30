#include <iostream>
#include <algorithm>
#include <string>
#include <climits>

#define MAX_LEN 20

using namespace std;

int n;
string expression;
string arrExpr[MAX_LEN];
int ans = INT_MIN;

void Init() {
	cin >> n;
	cin >> expression;
	for (int i = 0; i < n; i++) {
		arrExpr[i] = expression.substr(i, 1);
	}
}

void DFS(int cur, int len) {
	if (cur + 1  >= len) {	// 현재 괄호 시점이 문자열을 넘겼을 경우 계산
		int res = atoi(arrExpr[0].c_str());
		for (int i = 2; i < len; i += 2) {
			int val1 = res, val2 = atoi(arrExpr[i].c_str());
			string oper = arrExpr[i - 1];

			if (oper == "+") res = val1 + val2;
			else if (oper == "-") res = val1 - val2;
			else if (oper == "*") res = val1 * val2;
		}
		ans = max(ans, res);
		return;
	}

	DFS(cur + 2, len);	// 괄호없이 넘기기

	// 괄호 계산해서 넘기기
	for (int i = cur; i < len - 2; i += 2) {
		int val1 = atoi(arrExpr[i].c_str()), val2 = atoi(arrExpr[i + 2].c_str()), res;
		string oper = arrExpr[i + 1];

		if (oper == "+") res = val1 + val2;
		else if (oper == "-") res = val1 - val2;
		else if (oper == "*") res = val1 * val2;

		// DFS
		string save[MAX_LEN];
		for (int j = 0; j < len; j++) save[j] = arrExpr[j];	// save original
		
		for (int j = i + 1; j < len - 2; j++) arrExpr[j] = arrExpr[j + 2];	// cahnge expr
		arrExpr[i] = to_string(res);
		
		DFS(i + 2, len - 2);	// 다음 숫자부터 괄호 체크, 괄호 중복 방지
		
		for (int j = 0; j < len; j++) arrExpr[j] = save[j];	// recovery
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Init();
	DFS(0, n);

	cout << ans;
	return 0;
}