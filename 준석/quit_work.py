
def DFS(N, couns, index):
    res = []
    for i in range(index, N):
        days_left = N - i
        if(couns[i][0] <= days_left):
            res.append(couns[i][1] + DFS(N, couns, i + couns[i][0]))
    if(len(res) == 0):
        return 0
    else:
        #print(res)
        return max(res)

N = int(input().strip())

counseling = [[0]*2 for i in range(N)]

for i in range(N):
    counseling[i][0], counseling[i][1] = map(int, input().strip().split())

print(DFS(N, counseling, 0))
