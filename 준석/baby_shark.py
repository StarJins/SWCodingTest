from collections import namedtuple
point = namedtuple("point", "x y dist")

def expand_node(p, N, visited, to_visit):
    if(p.x > 0 and visited[p.x-1][p.y] == 0):
        to_visit.append(point(p.x-1, p.y, p.dist+1))
        visited[p.x-1][p.y] = 1
    if(p.y > 0 and visited[p.x][p.y-1] == 0):
        to_visit.append(point(p.x, p.y-1, p.dist+1))
        visited[p.x][p.y-1] = 1
    if(p.y < N-1 and visited[p.x][p.y+1] == 0):
        to_visit.append(point(p.x, p.y+1, p.dist+1))
        visited[p.x][p.y+1] = 1
    if(p.x < N-1 and visited[p.x+1][p.y] == 0):
        to_visit.append(point(p.x+1, p.y, p.dist+1))
        visited[p.x+1][p.y] = 1

def print_space(space, N):
    for i in range(N):
        for j in range(N):
            print(space[i][j], end = " ")
        print("")
    print("")

N = int(input().strip())
space = [[0]*N for i in range(N)]
shark = [0, 0]
size = 2
eaten_fish = 0
timer = 0

for i in range(N):
    instr = input().strip().split()
    for j in range(N):
        space[i][j] = int(instr[j])
        if int(instr[j]) == 9:
            shark[0] = i
            shark[1] = j

#implement bfs
cont_flag = True
while cont_flag:
    cont_flag = False
    to_visit = []
    visited = [[0]*N for i in range(N)]
    fishes = [[0]*N for i in range(N)]
    visited[shark[0]][shark[1]] = 1
    pnow = point(shark[0], shark[1], 0)
    expand_node(pnow, N, visited, to_visit)
    depth = 987654321
    flag1 = True

    while(len(to_visit) != 0):
        pnow = to_visit.pop(0)
        val = space[pnow.x][pnow.y]
        if(pnow.dist > depth):   #continue BFS on same depth
            break
        if(val > size):
            continue    #can't pass - forget this one
        elif(val < size and val != 0):  #found fish
            fishes[pnow.x][pnow.y] = pnow.dist
            depth = pnow.dist
            cont_flag = True
        else:   #passing through
            expand_node(pnow, N, visited, to_visit)

    flag = False
    for i in range(N):
        for j in range(N):
            if fishes[i][j] != 0:
                eaten_fish = eaten_fish + 1
                if eaten_fish == size:
                    size = size + 1
                    eaten_fish = 0
                space[shark[0]][shark[1]] = 0
                space[i][j] = 9
                timer = timer + fishes[i][j]
                #print_space(space, N)
                shark[0] = i
                shark[1] = j
                flag = True
                break
        if flag:
            break

print(timer)
