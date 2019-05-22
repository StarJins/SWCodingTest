#include <iostream>

using namespace std;

int main()
{
	int N, W;
	cin >> N >> W;
	int arr[1000000];
	int newarr[500001] = { 0 };			//500001¶«¿¡ Æ²·È¾úÀ½
	
	for (int i = 0; i < N-1; i++)
	{
		cin >> arr[2*i] >> arr[2*i + 1];
	}

	int floor = 0;
	for (int i = 0; i <2*(N-1); i++)
	{
		newarr[arr[i]]++;
	}
	for (int i = 2; i <= N; i++)
	{
		if (newarr[i] == 1)
		{
			floor++;
		}
	}

	cout.precision(6);
	cout << fixed<<(double)(W / (double)floor) << endl;

	system("pause");
	return 0;
}