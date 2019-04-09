from collections import namedtuple
point = namedtuple("point", "k n")


def in_range(num):
    if 0 <= num <= 500000:
        return True
    else:
        return False


def print_pos(pos, n, k):
    for i in range(n, k):
        print(i, end = " ")
    print("")
    for i in range(n, k):
        print(pos[0][i], end = " ")
    print("")
    for i in range(n, k):
        print(pos[1][i], end = " ")
    print("")
    print("")


if __name__ == "__main__":
    N, K = map(int, input().strip().split())

    if N == K:
        print(0)
        exit(0)

    loc = K
    Kloc = [K]
    move = 1
    while loc < 500000:
        loc = loc + move
        move = move + 1
        Kloc.append(loc)

    if Kloc[len(Kloc) - 1] > 500000:
        Kloc.pop()  # list of connie's locations up to 500000

    pos = [[-1]*500001 for i in range(2)]   # 홀짝 따로 위치표시
    pos[0][N] = 0
    posq = []
    posq.append(point(0, N))

    while len(posq) > 0:

        it = posq[0].k
        while len(posq) > 0 and posq[0].k == it:  # 같은 회차 탐색
            p = posq.pop(0)

            if in_range(p.n-1) and pos[(p.k+1)%2][p.n-1] == -1:
                pos[(p.k + 1) % 2][p.n - 1] = p.k + 1
                posq.append(point(p.k + 1, p.n - 1))
            if in_range(p.n + 1) and pos[(p.k + 1) % 2][p.n + 1] == -1:
                pos[(p.k + 1) % 2][p.n + 1] = p.k + 1
                posq.append(point(p.k + 1, p.n + 1))
            if in_range(p.n * 2) and pos[(p.k +1) % 2][p.n * 2] == -1:
                pos[(p.k + 1) % 2][p.n * 2] = p.k + 1
                posq.append(point(p.k + 1, p.n * 2))
            # print(it)
            # print_pos(pos, 0, 33)

        if it >= len(Kloc)-1:
            break
        if pos[0][Kloc[it+1]] != -1:
            print(it+1)
            exit(0)
        elif pos[1][Kloc[it+1]] == it + 1:
            print(it+1)
            exit(0)

    print(-1)