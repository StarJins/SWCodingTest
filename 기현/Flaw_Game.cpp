#include <iostream>
using namespace std;

int main() {
	int n;

	cin >> n;

	if (n % 4 == 3)
		cout << 2 << endl;

	else
		cout << 1 << endl;

	return 0;
}