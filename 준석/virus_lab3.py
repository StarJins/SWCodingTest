
from collections import namedtuple
import copy
point = namedtuple('point', 'x y d')
dx = [-1, 0, 0, 1]
dy = [0, -1, 1, 0]

def printb(N, b):
    for i in range(N):
        for j in range(N):
            print(b[i][j], end = " ")
        print("")
    print("")


def backtrack(vpoint, board, N, M, chosen, index, mini, count):
    num = len(vpoint)
    depth = 0
    if len(chosen) == M:
        visited = [[0] * N for i in range(N)]
        infected = 0
        to_visit = []
        for i in range(M):
            index = chosen[i]
            to_visit.append(vpoint[index])
            visited[vpoint[index].x][vpoint[index].y] = 1
        while len(to_visit) > 0 and infected != count:
            p = to_visit.pop(0)

            for i in range(4):
                curx = p.x + dx[i]
                cury = p.y + dy[i]
                if curx < 0 or curx >= N or cury < 0 or cury >= N:
                    continue
                if visited[curx][cury] == 1:
                    continue
                visited[curx][cury] = 1
                if board[curx][cury] == 1:
                    continue
                else:
                    to_visit.append(point(curx, cury, p.d + 1))
                    depth = p.d + 1
                    if board[curx][cury] == 0:
                        infected = infected + 1

        if count != infected:
            return
        if mini[0] > depth:
            mini[0] = depth
        return

    for i in range(index, num):
        ncho = copy.deepcopy(chosen)
        ncho.append(i)
        backtrack(vpoint, board, N, M, ncho, i + 1, mini, count)

'''
종료조건을 갯수 count로 바꿔보기
'''

if __name__ == '__main__':
    N, M = map(int, input().strip().split())
    board = [[0]* N for i in range(N)]
    vpoint = []
    count = 0
    for i in range(N):
        instr = input().strip().split()
        for j in range(N):
            board[i][j] = int(instr[j])
            if board[i][j] == 0:
                count = count + 1
            elif board[i][j] == 2:
                vpoint.append(point(i, j, 0))

    num = len(vpoint)
    chosen = []
    mini = [987654321]

    backtrack(vpoint, board, N, M, chosen, 0, mini, count)
    if mini[0] == 987654321:
        print(-1)
    else:
        print(mini[0])
