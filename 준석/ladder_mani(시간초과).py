def ladder_traversal(grid, N, M, start):
    for i in range(N):
        if(start > 0 and grid[i][start-1] == 1):
            start = start - 1
        elif start < M and grid[i][start] == 1: #앞의 조건문 없으면 OB 발생
            start = start + 1

    return start

def check_condition(grid, N, M):
    flag = True
    for i in range(M):
        temp = ladder_traversal(grid, N, M, i)
        if(temp != i):
            flag = False
            break
    return flag

def check_wall(grid, N, M, x, y):
    if grid[x][y] == 1:
        return False
    elif y > 0 and grid[x][y-1] == 1:
        return False
    elif y < M-1 and grid[x][y+1] == 1:
        return False
    else:
        return True
'''
def print_map(grid, N, M):
    for i in range(N):
        for j in range(M):
            print(grid[i][j], end = "")
        print("")
    print("")
'''
def DFS(grid, N, M, x, y, iter, res):
    #print_map(grid, N, M)
    if(iter == 3):
        return
    while x < N:
        while y < M:
            if check_wall(grid, N, M, x, y):
                grid[x][y] = 1
                iter = iter + 1
                if check_condition(grid, N, M):
                    res[0] = min(res[0], iter)
                    grid[x][y] = 0
                    return
                else:
                    DFS(grid, N, M, x, y, iter, res)
                    iter = iter - 1
                    grid[x][y] = 0
            y = y+1
        y = 0
        x = x+1

N, H, M = map(int, input().strip().split())

grid = [[0]*(N-1) for i in range(M)]
#이 배열은 선이 배치될 수 있는 공간을 나타냄: M x N-1
for i in range(H):
    x, y = map(int, input().strip().split())
    grid[x-1][y-1] = 1

res = [4]
if check_condition(grid, M, N-1):
    print(0)
else:
    DFS(grid, M, N-1, 0, 0, 0, res)
    if(res[0] == 4):
        print(-1)
    else:
        print(res[0])
