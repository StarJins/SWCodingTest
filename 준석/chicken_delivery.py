import copy
from collections import namedtuple
point = namedtuple("point", "x y")


def backtrack(chicken_dist, num, M, chosen, index, mini):
    if len(chosen) == M:
        houses = len(chicken_dist[0])
        temp = [987654321] * houses
        for i in range(houses):
            for j in range(M):
                if temp[i] > chicken_dist[chosen[j]][i]:
                    temp[i] = chicken_dist[chosen[j]][i]
        # print(temp)
        summ = sum(temp)
        if mini[0] > summ:
            mini[0] = summ
        return

    for i in range(index, num):
        n_cho = copy.deepcopy(chosen)
        n_cho.append(i)
        backtrack(chicken_dist, num, M, n_cho, i+1, mini)


if __name__ == "__main__":
    N, M = map(int, input().strip().split())

    board = [[0]*N for i in range(N)]
    chicken = []
    for i in range(N):
        instr = input().strip().split()
        for j in range(N):
            temp = int(instr[j])
            board[i][j] = temp
            if temp == 2:
                chicken.append(point(i, j))

    num = len(chicken)
    chicken_dist = [[] for i in range(num)]

    for i in range(N):
        for j in range(N):
            if board[i][j] == 1:    # 각 상점마다 모든 집과의 치킨 거리 구하기
                for k in range(num):
                    chicken_dist[k].append(abs(chicken[k].x - i) + abs(chicken[k].y - j))

    mini = [987654321]
    chosen = []

    backtrack(chicken_dist, num, M, chosen, 0, mini)

    print(mini[0])