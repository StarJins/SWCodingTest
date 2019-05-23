#include <iostream>
using namespace std;

int arr[10000];
int n;

int find(int arr[10000]) {
	int i;
	int tmp;
	int cnt = 0;
	int down = 0;

	for (i = 0; i < n-1; i++) {
		if (arr[i] == arr[i + 1]) {
			cnt = cnt + 2;
			tmp = i + 2;
			while (arr[i] == arr[tmp]) {
				cnt++;
				tmp++;
			}
			i = tmp-1;
		}
		else if (arr[i] > arr[i + 1]) {
			down++;
			if (down > 1) {
				return 0;
			}

			if (i < n - 2 && arr[i] == arr[i + 2])
				cnt++;
			else if (i > 0 && arr[i + 1] == arr[i - 1])
				cnt++;
			if (i == n - 2)
				cnt++;
		}
	}

	return cnt;
}

int main() {
	int i;
	int result;

	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	result = find(arr);

	cout << result << endl;

	return 0;
}


/*

//vector 이용한 방법

void print(vector<int> arr) {
	for (vector<int>::size_type i = 0; i < arr.size(); i++) {
		cout << arr[i] << '\t';
	}
	cout << endl;
}


int main() {
	int i;
	int n;
	int input;
	int result = 0;
	int cnt = 0;
	bool isSame;
	vector<int> arr;
	vector<int> eArr;
	vector<int> sArr;
	vector<int>::iterator iter;

	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> input;
		arr.push_back(input);
	}

	
	while (cnt < n) {
		for (vector<int>::size_type j = 0; j < arr.size(); j++) {
			eArr.push_back(arr[j]);
		}
		//print(eArr);
		vector<int>::iterator iter = eArr.begin() + cnt;
		eArr.erase(iter);
		for (vector<int>::size_type j = 0; j < eArr.size(); j++) {
			sArr.push_back(eArr[j]);
		}
		//print(sArr);
		sort(sArr.begin(), sArr.end());
		//print(sArr);
		isSame = true;
		for (vector<int>::size_type j = 0; j < eArr.size(); j++) {
			if (sArr[j] != eArr[j]) {
				isSame = false;
				break;
			}
		}

		if (isSame) {
			result++;
		}
		cnt++;
		eArr.clear();
		sArr.clear();
		//cout << "=====================================" << endl;
	}

	cout << result << endl;


	return 0;
}*/