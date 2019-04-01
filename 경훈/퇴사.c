#include <stdio.h>
#include <stdlib.h>


struct DAP {
	int day;
	int pay;
};
int Max = 0;
struct DAP D[15];
void remove_meanless(int N);
void DFS(int N, int day, int max_pay);

int main()
{
	int N;
	int i;


	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d %d", &D[i].day, &D[i].pay);
	}

	remove_meanless(N);

    DFS(N, 0, 0);
//    printf("%d\n", N);
//	for (i = 0; i < N; i++)
//	{
//		printf("%d %d\n", D[i].day, D[i].pay);
//	}

    printf("%d", Max);


    return 0;
}


void remove_meanless(int N)
{
    int i;
    for(i = 0; i < N; i++)
    {
        if(D[i].day + i >N)
        {
            D[i].day = 1;
            D[i].pay = 0;
        }
    }
}
void DFS(int N, int day, int max_pay)
{
    int i;
    int before = max_pay;
    for(i = day; i < N; i++)
    {
        if(i > N)
        {
            return;
        }
        max_pay += D[i].pay;
        DFS(N, i+D[i].day, max_pay);
        max_pay = before;
    }
	if(max_pay > Max)
        {
            Max = max_pay;
        }
}
