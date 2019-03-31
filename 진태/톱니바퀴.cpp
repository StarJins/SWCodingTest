#include <iostream>
#include <string>

using namespace std;

int gear[5][8];
int check[4];
int k;

void Init() {
	for (int i = 1; i < 5; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < 8; j++) {
			gear[i][j] = temp[j] - '0';
		}
	}
}

void Check() {
	for (int i = 0; i < 4; i++)
		check[i] = 0;

	for (int i = 1; i < 4; i++) {
		if (gear[i][2] != gear[i + 1][6])
			check[i] = 1;
	}
}

void Rotate(int idx, int d) {
	if (d == 1) {	// �ð� ����
		int temp = gear[idx][7];
		for (int i = 7; i > 0; i--)
			gear[idx][i] = gear[idx][i - 1];
		gear[idx][0] = temp;
	}
	else {			// �ݽð� ����
		int temp = gear[idx][0];
		for (int i = 0; i < 7; i++)
			gear[idx][i] = gear[idx][i + 1];
		gear[idx][7] = temp;
	}
}

void Run(int idx, int d) {
	Rotate(idx, d);	// �Է¹��� ��� ������

	int temp = d;
	for (int i = idx - 1; i >= 1; i--) {		// ���� ��� �� Ȯ���ؼ� ������
		temp = (temp == -1) ? 1 : -1;
		if (check[i] == 1)
			Rotate(i, temp);				// ���� Ȯ���� ���� �ε��� �״��
		else
			break;
	}

	temp = d;
	for (int i = idx; i < 4; i++) {			// ������ ��� �� Ȯ���ؼ� ������
		temp = (temp == -1) ? 1 : -1;
		if (check[i] == 1)
			Rotate(i + 1, temp);			// ������ Ȯ���� ���� �ε������� +1, check������ 1-2, 2-3, 3-4 �̷��� ��� üũ�ϱ� �����̴�
		else
			break;
	}
}

int Cal() {
	return gear[1][0] + gear[2][0] * 2 + gear[3][0] * 4 + gear[4][0] * 8;
}

int main() {
	Init();
	cin >> k;

	for (int i = 0; i < k; i++) {
		int idx, d;
		cin >> idx >> d;

		Check();		// ���� �� Ȯ��
		Run(idx, d);	// ������
	}

	cout << Cal();
	return 0;
}