#include <iostream>
using namespace std;

int node[500001] = { 0 };

int main() {
	int n, w;
	int i;
	int ip1, ip2;
	double leaf = 0;
	double result;
	cin >> n >> w;

	for (i = 0; i < n-1; i++) {
		cin >> ip1 >> ip2;
		if (node[ip1] < 2)
			node[ip1]++;
		if (node[ip2] < 2)
			node[ip2]++;
	}

	for (i = 2; i <= 500000; i++) {
		if (node[i] == 1)
			leaf++;
	}
	
	result = w / leaf;
	
	cout.precision(6); 
	cout << fixed << result << endl;
	//cout << result << endl;

	return 0;
}