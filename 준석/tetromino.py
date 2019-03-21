
from collections import namedtuple

point = namedtuple('point', 'x y')
#전수검사 혹은
#DFS로 가능할듯 하다
#일단은 DFS로 코딩함

def DFS(map, N, M, pos, iter, visited):
    visited.add(pos)
    if(iter == 4):
        #base case
        return map[pos.x][pos.y]
    res = [0]*4
    #4방향에 대해 DFS 호출
    #단, 각 점이 OB는 아닌지, visited에 들어있는지 확인
    #visited는 각 다른 시작점마다 초기화됨
    if(pos.x != 0 and point(pos.x-1, pos.y) not in visited):
        res[0] = DFS(map, N, M, point(pos.x-1, pos.y), iter+1, visited)
    if(pos.x != N-1 and point(pos.x+1, pos.y) not in visited):
        res[1] = DFS(map, N, M, point(pos.x+1, pos.y), iter+1, visited)
    if(pos.y != 0 and point(pos.x, pos.y-1) not in visited):
        res[2] = DFS(map, N, M, point(pos.x, pos.y-1), iter+1, visited)
    if(pos.y != M-1 and point(pos.x, pos.y+1) not in visited):
        res[3] = DFS(map, N, M, point(pos.x, pos.y+1), iter+1, visited)
    max = 0
    for i in range(4):
        if max < res[i]:
            max = res[i]
    return max + map[pos.x][pos.y]


N, M = map(int, input().strip().split())
map = [[0]*M for i in range(N)]
for i in range(N):
    instr = input().strip().split()
    for j in range(M):
        map[i][j] = int(instr[j])

visited = set()
max = 0
for i in range(N):
    for j in range(M):
        visited.clear()
        temp = DFS(map, N, M, point(i, j), 1, visited)
        if max < temp:
            max = temp

for i in range(N-2):
    for j in range(M-2):
        temp = [0]*4
        temp[0] = map[i+1][j+1] + map[i][j+1] + map[i+1][j] + map[i+2][j+1]
        temp[1] = map[i+1][j+1] + map[i][j+1] + map[i+1][j] + map[i+1][j+2]
        temp[2] = map[i+1][j+1] + map[i][j+1] + map[i+1][j+2] + map[i+2][j+1]
        temp[3] = map[i+1][j+1] + map[i+1][j] + map[i+1][j+2] + map[i+2][j+1]
        for k in range(4):
            if max < temp[k]:
                max = temp[k]
            
print(max)

#print(map)
