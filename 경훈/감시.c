#include <stdio.h>
#include <stdlib.h>

int mapA[8][8];
int mapB[8][8];
int Min = 64;

struct data
{
    int i;
    int j;
    int data;
};
struct data D[64];
int N,M;

void DFS(int data);
void Howtomove(int data, int direction);
void refresh(int data, int direction);
void CCTV1(int data,int direction);
void CCTV2(int data,int direction);
void CCTV3(int data,int direction);
void CCTV4(int data,int direction);
void CCTV5(int data,int direction);
void rCCTV1(int data,int direction);
void rCCTV2(int data,int direction);
void rCCTV3(int data,int direction);
void rCCTV4(int data,int direction);
void rCCTV5(int data,int direction);

int main()
{
    int k = 0;
    scanf("%d %d", &N,&M);

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            scanf("%d", &mapA[i][j]);
            mapB[i][j] = mapA[i][j];
            if(mapA[i][j] != 0 && mapA[i][j] != 6)
            {
                D[k].i = i;
                D[k].j = j;
                D[k++].data = mapA[i][j];
            }
        }
    }
    DFS(0);
    printf("%d", Min);

    return 0;

}

void Howtomove(int data, int direction)     // data is CCTV count
{
    switch(D[data].data)
    {
    case 0: break;
    case 1: CCTV1(data,direction); break;
    case 2: CCTV2(data,direction); break;
    case 3: CCTV3(data,direction); break;
    case 4: CCTV4(data,direction); break;
    case 5: CCTV5(data,direction); break;
    }
}

void CCTV1(int data,int direction)
{
    int i = D[data].i;
    int j = D[data].j;
    if(direction == 0)
    {
        for(j++;j < M;j++)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 0)
            {
                mapB[i][j] = 7;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]++;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
    }
    else if(direction == 1)
    {
        for(j--; j >= 0;j--)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 0)
            {
                mapB[i][j] = 7;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]++;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
    }
    else if(direction == 2)
    {
        for(i++; i < N ;i++)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 0)
            {
                mapB[i][j] = 7;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]++;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
    }
    else if(direction == 3)
    {
        for(i--; i >= 0 ;i--)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 0)
            {
                mapB[i][j] = 7;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]++;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
    }
}
void CCTV2(int data,int direction)
{
    int i = D[data].i;
    int j = D[data].j;
    if(direction == 0)
    {
        for(j++;j < M;j++)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 0)
            {
                mapB[i][j] = 7;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]++;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
        for(j = D[data].j -1; j >= 0;j--)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 0)
            {
                mapB[i][j] = 7;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]++;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
    }
    else if(direction == 1)
    {
        for(i++; i < N ;i++)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 0)
            {
                mapB[i][j] = 7;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]++;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
        for(i = D[data].i -1; i >= 0 ;i--)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 0)
            {
                mapB[i][j] = 7;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]++;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
    }

}
void CCTV3(int data,int direction)
{
    int i = D[data].i;
    int j = D[data].j;
    if(direction == 0)
    {
        for(j++;j < M;j++)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 0)
            {
                mapB[i][j] = 7;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]++;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
        for(i++, j = D[data].j; i < N ;i++)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 0)
            {
                mapB[i][j] = 7;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]++;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
    }
    else if(direction == 1)
    {
        for(j++;j < M;j++)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 0)
            {
                mapB[i][j] = 7;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]++;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
        for(i--, j = D[data].j; i >= 0 ;i--)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 0)
            {
                mapB[i][j] = 7;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]++;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
    }
    else if(direction == 2)
    {
        for(j--; j >= 0;j--)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 0)
            {
                mapB[i][j] = 7;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]++;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
        for(i++, j = D[data].j; i < N ;i++)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 0)
            {
                mapB[i][j] = 7;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]++;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
    }
    else if(direction == 3)
    {
        for(j--; j >= 0;j--)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 0)
            {
                mapB[i][j] = 7;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]++;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
        for(i--, j = D[data].j; i >= 0 ;i--)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 0)
            {
                mapB[i][j] = 7;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]++;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }

        }
    }

}
void CCTV4(int data,int direction)
{
    int i = D[data].i;
    int j = D[data].j;
    if(direction == 0)
    {
        for(j++; j < M;j++)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 0)
            {
                mapB[i][j] = 7;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]++;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
        for(i++, j = D[data].j; i < N ;i++)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 0)
            {
                mapB[i][j] = 7;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]++;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
        for(i = D[data].i -1, j = D[data].j; i >= 0 ;i--)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 0)
            {
                mapB[i][j] = 7;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]++;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
    }
    else if(direction == 1)
    {
        for(j++; j < M;j++)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 0)
            {
                mapB[i][j] = 7;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]++;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
        for(i--, j = D[data].j; i >= 0 ;i--)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 0)
            {
                mapB[i][j] = 7;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]++;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
        for(j = D[data].j -1, i = D[data].i; j >= 0;j--)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 0)
            {
                mapB[i][j] = 7;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]++;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
    }
    else if(direction == 2)
    {
        for(j--; j >= 0;j--)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 0)
            {
                mapB[i][j] = 7;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]++;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
        for(i++, j = D[data].j; i < N ;i++)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 0)
            {
                mapB[i][j] = 7;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]++;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
        for(j = D[data].j +1, i = D[data].i; j < M;j++)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 0)
            {
                mapB[i][j] = 7;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]++;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
    }
    else if(direction == 3)
    {
        for(j--; j >= 0;j--)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 0)
            {
                mapB[i][j] = 7;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]++;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
        for(i--, j = D[data].j; i >= 0 ;i--)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 0)
            {
                mapB[i][j] = 7;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]++;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
        for(i= D[data].i+1, j = D[data].j; i < N ;i++)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 0)
            {
                mapB[i][j] = 7;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]++;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
    }
}
void CCTV5(int data,int direction)
{
    int i = D[data].i;
    int j = D[data].j;
    for(j--;j >= 0;j--)       //avoid the wall and out of the map
    {
        if(mapB[i][j] == 0)
        {
            mapB[i][j] = 7;
        }
        else if(mapB[i][j] >= 7)
        {
            mapB[i][j]++;
        }
        else if(mapB[i][j] == 6)
        {
            break;
        }
    }
    for(i--, j = D[data].j; i >= 0 ;i--)       //avoid the wall and out of the map
    {
        if(mapB[i][j] == 0)
        {
            mapB[i][j] = 7;
        }
        else if(mapB[i][j] >= 7)
        {
            mapB[i][j]++;
        }
        else if(mapB[i][j] == 6)
        {
            break;
        }
    }
    for(i= D[data].i+1, j = D[data].j; i < N ;i++)       //avoid the wall and out of the map
    {
        if(mapB[i][j] == 0)
        {
            mapB[i][j] = 7;
        }
        else if(mapB[i][j] >= 7)
        {
            mapB[i][j]++;
        }
        else if(mapB[i][j] == 6)
        {
            break;
        }
    }
    for(j = D[data].j +1, i = D[data].i; j < M;j++)       //avoid the wall and out of the map
    {
        if(mapB[i][j] == 0)
        {
            mapB[i][j] = 7;
        }
        else if(mapB[i][j] >= 7)
        {
            mapB[i][j]++;
        }
        else if(mapB[i][j] == 6)
        {
            break;
        }
    }
}
void refresh(int data, int direction)
{
    switch(D[data].data)
    {
    case 0: break;
    case 1: rCCTV1(data,direction); break;
    case 2: rCCTV2(data,direction); break;
    case 3: rCCTV3(data,direction); break;
    case 4: rCCTV4(data,direction); break;
    case 5: rCCTV5(data,direction); break;
    }
}
void rCCTV1(int data,int direction)
{
    int i = D[data].i;
    int j = D[data].j;
    if(direction == 0)
    {
        for(j++;j < M;j++)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 7)
            {
                mapB[i][j] = 0;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]--;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
    }
    else if(direction == 1)
    {
        for(j--; j >= 0;j--)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 7)
            {
                mapB[i][j] = 0;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]--;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
    }
    else if(direction == 2)
    {
        for(i++; i < N ;i++)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 7)
            {
                mapB[i][j] = 0;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]--;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
    }
    else if(direction == 3)
    {
        for(i--; i >= 0 ;i--)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 7)
            {
                mapB[i][j] = 0;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]--;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
    }
}
void rCCTV2(int data,int direction)
{
    int i = D[data].i;
    int j = D[data].j;
    if(direction == 0)
    {
        for(j++;j < M;j++)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 7)
            {
                mapB[i][j] = 0;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]--;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
        for(j = D[data].j -1; j >= 0;j--)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 7)
            {
                mapB[i][j] = 0;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]--;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
    }
    else if(direction == 1)
    {
        for(i++; i < N ;i++)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 7)
            {
                mapB[i][j] = 0;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]--;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
        for(i = D[data].i -1; i >= 0 ;i--)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 7)
            {
                mapB[i][j] = 0;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]--;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
    }
}
void rCCTV3(int data,int direction)
{
    int i = D[data].i;
    int j = D[data].j;
    if(direction == 0)
    {
        for(j++;j < M;j++)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 7)
            {
                mapB[i][j] = 0;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]--;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
        for(i++, j = D[data].j; i < N ;i++)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 7)
            {
                mapB[i][j] = 0;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]--;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
    }
    else if(direction == 1)
    {
        for(j++;j < M;j++)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 7)
            {
                mapB[i][j] = 0;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]--;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
        for(i--, j = D[data].j; i >= 0 ;i--)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 7)
            {
                mapB[i][j] = 0;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]--;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
    }
    else if(direction == 2)
    {
        for(j--; j >= 0;j--)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 7)
            {
                mapB[i][j] = 0;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]--;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
        for(i++, j = D[data].j; i < N ;i++)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 7)
            {
                mapB[i][j] = 0;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]--;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
    }
    else if(direction == 3)
    {
        for(j--; j >= 0;j--)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 7)
            {
                mapB[i][j] = 0;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]--;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
        for(i--, j = D[data].j; i >= 0 ;i--)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 7)
            {
                mapB[i][j] = 0;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]--;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }

        }
    }
}
void rCCTV4(int data,int direction)
{
    int i = D[data].i;
    int j = D[data].j;
    if(direction == 0)
    {
        for(j++; j < M;j++)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 7)
            {
                mapB[i][j] = 0;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]--;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
        for(i++, j = D[data].j; i < N ;i++)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 7)
            {
                mapB[i][j] = 0;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]--;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
        for(i = D[data].i -1, j = D[data].j; i >= 0 ;i--)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 7)
            {
                mapB[i][j] = 0;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]--;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
    }
    else if(direction == 1)
    {
        for(j++; j < M;j++)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 7)
            {
                mapB[i][j] = 0;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]--;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
        for(i--, j = D[data].j; i >= 0 ;i--)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 7)
            {
                mapB[i][j] = 0;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]--;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
        for(j = D[data].j -1, i = D[data].i; j >= 0;j--)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 7)
            {
                mapB[i][j] = 0;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]--;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
    }
    else if(direction == 2)
    {
        for(j--; j >= 0;j--)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 7)
            {
                mapB[i][j] = 0;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]--;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
        for(i++, j = D[data].j; i < N ;i++)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 7)
            {
                mapB[i][j] = 0;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]--;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
        for(j = D[data].j +1, i = D[data].i; j < M;j++)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 7)
            {
                mapB[i][j] = 0;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]--;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
    }
    else if(direction == 3)
    {
        for(j--; j >= 0;j--)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 7)
            {
                mapB[i][j] = 0;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]--;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
        for(i--, j = D[data].j; i >= 0 ;i--)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 7)
            {
                mapB[i][j] = 0;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]--;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
        for(i= D[data].i+1, j = D[data].j; i < N ;i++)       //avoid the wall and out of the map
        {
            if(mapB[i][j] == 7)
            {
                mapB[i][j] = 0;
            }
            else if(mapB[i][j] >= 7)
            {
                mapB[i][j]--;
            }
            else if(mapB[i][j] == 6)
            {
                break;
            }
        }
    }
}
void rCCTV5(int data,int direction)
{
    int i = D[data].i;
    int j = D[data].j;
    for(j--;j >= 0;j--)       //avoid the wall and out of the map
    {
        if(mapB[i][j] == 7)
        {
            mapB[i][j] = 0;
        }
        else if(mapB[i][j] >= 7)
        {
            mapB[i][j]--;
        }
        else if(mapB[i][j] == 6)
        {
            break;
        }
    }
    for(i--, j = D[data].j; i >= 0 ;i--)       //avoid the wall and out of the map
    {
        if(mapB[i][j] == 7)
        {
            mapB[i][j] = 0;
        }
        else if(mapB[i][j] >= 7)
        {
            mapB[i][j]--;
        }
        else if(mapB[i][j] == 6)
        {
            break;
        }
    }
    for(i= D[data].i+1, j = D[data].j; i < N ;i++)       //avoid the wall and out of the map
    {
        if(mapB[i][j] == 7)
        {
            mapB[i][j] = 0;
        }
        else if(mapB[i][j] >= 7)
        {
            mapB[i][j]--;
        }
        else if(mapB[i][j] == 6)
        {
            break;
        }
    }
    for(j = D[data].j +1, i = D[data].i; j < M;j++)       //avoid the wall and out of the map
    {
        if(mapB[i][j] == 7)
        {
            mapB[i][j] = 0;
        }
        else if(mapB[i][j] >= 7)
        {
            mapB[i][j]--;
        }
        else if(mapB[i][j] == 6)
        {
            break;
        }
    }
}
void DFS(int data)
{
    int i ,j,k;
    int direction;
    int count = 0;

    if(D[data].data==0)
    {
        for(i = 0; i < N; i++)              //counting part
        {
            for(k = 0; k < M; k++)
            {
                if(mapB[i][k] == 0)
                {
                    count++;
                }
            }
        }

        if(count < Min)
        {
            Min = count;
        }

        return;
    }


    switch(D[data].data)
    {
        case 1: direction = 4; break;
        case 2: direction = 2; break;
        case 3: direction = 4; break;
        case 4: direction = 4; break;
        case 5: direction = 1; break;
    }

    for(j = 0; j< direction;j++)
    {

        Howtomove(data,j);
        DFS(data+1);
        refresh(data, j);

    }
}
