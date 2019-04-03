from collections import namedtuple
import copy
cam = namedtuple("cam", "x y type")

def color(map, N, M, x, y, dir):
    if dir == 0:    #left
        for i in range(y-1, -1, -1):
            if(map[x][i] == 6):
                break
            elif(map[x][i] == 0):
                map[x][i] = '#'
    elif dir == 1: #up
        for i in range(x-1, -1, -1):
            if(map[i][y] == 6):
                break
            elif(map[i][y] == 0):
                map[i][y] = '#'
    elif dir == 2:    #right
        for i in range(y, M):
            if(map[x][i] == 6):
                break
            elif(map[x][i] == 0):
                map[x][i] = '#'
    elif dir == 3: #down
        for i in range(x, N):
            if(map[i][y] == 6):
                break
            elif(map[i][y] == 0):
                map[i][y] = '#'

def counter(space, N, M):
    sum = 0
    for i in range(N):
        sum = sum + space[i].count(0)
    return sum

def DFS(space, N, M, cams):
    if len(cams) == 0:
        #print(space)
        return counter(space, N, M)
    newcam = copy.deepcopy(cams)
    c1 = newcam.pop()
    if(c1.type == 5):
        newboard = copy.deepcopy(space)
        for i in range(4):
            color(newboard, N, M, c1.x, c1.y, i)
        return DFS(newboard, N, M, newcam)
    elif(c1.type == 2):
        #case 1
        newboard = copy.deepcopy(space)
        color(newboard, N, M, c1.x, c1.y, 0)
        color(newboard, N, M, c1.x, c1.y, 2)
        res1 = DFS(newboard, N, M, newcam)
        #case 2
        newboard = copy.deepcopy(space)
        color(newboard, N, M, c1.x, c1.y, 1)
        color(newboard, N, M, c1.x, c1.y, 3)
        res2 = DFS(newboard, N, M, newcam)
        return min(res1, res2)
    elif(c1.type == 1):
        res = [0]*4
        newboard = copy.deepcopy(space)
        color(newboard, N, M, c1.x, c1.y, 0)
        res[0] = DFS(newboard, N, M, newcam)

        newboard = copy.deepcopy(space)
        color(newboard, N, M, c1.x, c1.y, 1)
        res[1] = DFS(newboard, N, M, newcam)

        newboard = copy.deepcopy(space)
        color(newboard, N, M, c1.x, c1.y, 2)
        res[2] = DFS(newboard, N, M, newcam)

        newboard = copy.deepcopy(space)
        color(newboard, N, M, c1.x, c1.y, 3)
        res[3] = DFS(newboard, N, M, newcam)

        return min(res)
    elif(c1.type == 3):
        res = [0]*4
        newboard = copy.deepcopy(space)
        color(newboard, N, M, c1.x, c1.y, 0)
        color(newboard, N, M, c1.x, c1.y, 1)
        res[0] = DFS(newboard, N, M, newcam)

        newboard = copy.deepcopy(space)
        color(newboard, N, M, c1.x, c1.y, 1)
        color(newboard, N, M, c1.x, c1.y, 2)
        res[1] = DFS(newboard, N, M, newcam)

        newboard = copy.deepcopy(space)
        color(newboard, N, M, c1.x, c1.y, 2)
        color(newboard, N, M, c1.x, c1.y, 3)
        res[2] = DFS(newboard, N, M, newcam)

        newboard = copy.deepcopy(space)
        color(newboard, N, M, c1.x, c1.y, 3)
        color(newboard, N, M, c1.x, c1.y, 0)
        res[3] = DFS(newboard, N, M, newcam)

        return min(res)
    elif(c1.type == 4):
        res = [0]*4
        newboard = copy.deepcopy(space)
        color(newboard, N, M, c1.x, c1.y, 0)
        color(newboard, N, M, c1.x, c1.y, 1)
        color(newboard, N, M, c1.x, c1.y, 2)
        res[0] = DFS(newboard, N, M, newcam)

        newboard = copy.deepcopy(space)
        color(newboard, N, M, c1.x, c1.y, 1)
        color(newboard, N, M, c1.x, c1.y, 2)
        color(newboard, N, M, c1.x, c1.y, 3)
        res[1] = DFS(newboard, N, M, newcam)

        newboard = copy.deepcopy(space)
        color(newboard, N, M, c1.x, c1.y, 2)
        color(newboard, N, M, c1.x, c1.y, 3)
        color(newboard, N, M, c1.x, c1.y, 0)
        res[2] = DFS(newboard, N, M, newcam)

        newboard = copy.deepcopy(space)
        color(newboard, N, M, c1.x, c1.y, 3)
        color(newboard, N, M, c1.x, c1.y, 0)
        color(newboard, N, M, c1.x, c1.y, 1)
        res[3] = DFS(newboard, N, M, newcam)

        return min(res)


N, M = map(int, input().strip().split())

space = [[0]*M for i in range(N)]
cams = []

for i in range(N):
    instr = input().strip().split()
    for j in range(M):
        space[i][j] = int(instr[j])
        if(space[i][j] > 0 and space[i][j] < 6):
            cams.append(cam(i, j, space[i][j]))

print(DFS(space, N, M, cams))
'''
c1 = cams.pop()
color(space, N, M, c1.x, c1.y, 2)
color(space, N, M, c1.x, c1.y, 0)
print(counter(space, N, M))
'''
