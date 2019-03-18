import copy
#import queue
from collections import namedtuple

point = namedtuple("point", "x y")

def spread_virus(map, N, M, max):   #bfs 반복문
    #print(map)
    q = set()
    for i in range(N):
        for j in range(M):
            if(map[i][j] == 2):
                q.add(point(i, j))  #바이러스가 있는 좌표를 후보 큐에 삽입
    while(len(q) != 0):
        #탐색 순서: 하우상좌
        p1 = q.pop()
        map[p1.x][p1.y] = 2
        if(p1.x < N-1 and map[p1.x+1][p1.y] == 0):
            q.add(point((p1.x+1), p1.y))
        if(p1.y < M-1 and map[p1.x][p1.y+1] == 0):
            q.add(point(p1.x, (p1.y+1)))
        if(p1.x > 0 and map[p1.x-1][p1.y] == 0):
            q.add(point((p1.x-1), p1.y))
        if(p1.y > 0 and map[p1.x][p1.y-1] == 0):
            q.add(point(p1.x, (p1.y-1)))

    count = 0
    for i in range(N):
        for j in range(M):
            if(map[i][j] == 0):
                count = count + 1
    if(count > max[0]):
        max[0] = count

def construct_wall(map, N, M, index_n, index_m, iter, max): #dfs 반복문
    i = index_n
    j = index_m
    while(i < N):
        while(j < M):
            new_n = i
            new_m = j
            if(map[i][j] == 0): #빈칸이면 벽 세움
                map[i][j] = 1
                iter = iter + 1
                if(iter == 3): #벽 3개면 멈추고 계산, 이후 벽 지우고 다음칸
                    smap = copy.deepcopy(map) #map 변경은 복사해서
                    spread_virus(smap, N, M, max)
                else:
                    construct_wall(map, N, M, i, j, iter, max) #다음 재귀: 이 칸은 1이므로 다음칸에 세움.
                map[i][j] = 0   #세웠던 벽 지우고 다음 반복
                iter = iter - 1

            else:   #바이러스 or 벽 칸이면 다음으로 이동
                j = j + 1
                continue
            j = j + 1
        j = 0
        i = i + 1


#행/렬 및 맵 입력
instr = input()
inspl = instr.split()
map_n = int(inspl[0])
map_m = int(inspl[1])

map = [[0]*map_m for i in range(map_n)]

for i in range(map_n):
    instr = input()
    inspl = instr.split()
    for j in range(map_m):
        map[i][j] = int(inspl[j])

max = [0]   #안전영역 최댓값 저장
#벽을 배치하는 코드
construct_wall(map, map_n, map_m, 0, 0, 0, max)
#배치 후 바이러스를 퍼트리는 코드 - spread_virus

print(max[0])
