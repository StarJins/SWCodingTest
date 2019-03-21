from collections import namedtuple

point = namedtuple('point', 'x y')

#전수검사 버전
def stamp(map, N, M, mask, n, m):
    max = 0
    for i in range(N-n+1):
        for j in range(M-m+1):
            sum = 0
            for k in range(n):
                for l in range(m):
                    sum = sum + map[i+k][j+l]*grid[k][l]
            if sum > max:
                max = sum
    return max


N, M = map(int, input().strip().split())
map = [[0]*M for i in range(N)]
for i in range(N):
    instr = input().strip().split()
    for j in range(M):
        map[i][j] = int(instr[j])

res = []

grid = [[1, 1, 1, 1]]
res.append(stamp(map, N, M, grid, 1, 4))
grid = [[1],
        [1],
        [1],
        [1]]
res.append(stamp(map, N, M, grid, 4, 1))
grid = [[1, 1],
        [1, 1]]
res.append(stamp(map, N, M, grid, 2, 2))
grid = [[1, 0],
        [1, 1],
        [0, 1]]
res.append(stamp(map, N, M, grid, 3, 2))
grid = [[0, 1],
        [1, 1],
        [1, 0]]
res.append(stamp(map, N, M, grid, 3, 2))
grid = [[1, 1, 0],
        [0, 1, 1]]
res.append(stamp(map, N, M, grid, 2, 3))
grid = [[0, 1, 1],
        [1, 1, 0]]
res.append(stamp(map, N, M, grid, 2, 3))
grid = [[1, 0],
        [1, 1],
        [1, 0]]
res.append(stamp(map, N, M, grid, 3, 2))
grid = [[0, 1],
        [1, 1],
        [0, 1]]
res.append(stamp(map, N, M, grid, 3, 2))
grid = [[0, 1, 0],
        [1, 1, 1]]
res.append(stamp(map, N, M, grid, 2, 3))
grid = [[1, 1, 1],
        [0, 1, 0]]
res.append(stamp(map, N, M, grid, 2, 3))
grid = [[1, 0],
        [1, 0],
        [1, 1]]
res.append(stamp(map, N, M, grid, 3, 2))
grid = [[0, 1],
        [0, 1],
        [1, 1]]
res.append(stamp(map, N, M, grid, 3, 2))
grid = [[1, 1],
        [1, 0],
        [1, 0]]
res.append(stamp(map, N, M, grid, 3, 2))
grid = [[1, 1],
        [0, 1],
        [0, 1]]
res.append(stamp(map, N, M, grid, 3, 2))
grid = [[1, 0, 0],
        [1, 1, 1]]
res.append(stamp(map, N, M, grid, 2, 3))
grid = [[1, 1, 1],
        [1, 0, 0]]
res.append(stamp(map, N, M, grid, 2, 3))
grid = [[0, 0, 1],
        [1, 1, 1]]
res.append(stamp(map, N, M, grid, 2, 3))
grid = [[1, 1, 1],
        [0, 0, 1]]
res.append(stamp(map, N, M, grid, 2, 3))

max = 0
for i in range(len(res)):
    if max < res[i]:
        max = res[i]

print(max)
