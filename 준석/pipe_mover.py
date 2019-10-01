import copy


def backtrack(N, px, py, dir, room, count):
    # dir 0
    if dir == 0:
        #base:
        if px == N-1 and py == N-2:
            count[0] += 1
            return
        # op1
        if py + 2 < N and room[px][py+2] == 0:
            backtrack(N, px, py+1, 0, room, count)
        # op2
        if px + 1 < N and py + 2 < N and room[px][py+2] == 0 and room[px+1][py+1] == 0 and room[px+1][py+2] == 0:
            backtrack(N, px, py+1, 2, room, count)

    # dir 1
    elif dir == 1:
        # base:
        if px == N-2 and py == N-1:
            count[0] += 1
            return
        # op1
        if px + 2 < N and room[px+2][py] == 0:
            backtrack(N, px+1, py, 1, room, count)
        # op2
        if px + 2 < N and py + 1 < N and room[px+2][py] == 0 and room[px+1][py+1] == 0 and room[px+2][py+1] == 0:
            backtrack(N, px+1, py, 2, room, count)

    # dir 2
    else:
        # base:
        if px == N - 2 and py == N - 2:
            count[0] += 1
            return
        # op1
        if px + 1 < N and py + 2 < N and room[px+1][py+2] == 0:
            backtrack(N, px+1, py+1, 0, room, count)
        # op2
        if px + 2 < N and py + 1 < N and room[px+2][py+1] == 0:
            backtrack(N, px+1, py+1, 1, room, count)
        # op3
        if px + 2 < N and py + 2 < N and room[px+2][py+1] == 0 and room[px+1][py+2] == 0 and room[px+2][py+2] == 0:
            backtrack(N, px+1, py+1, 2, room, count)


if __name__ == "__main__":
    N = int(input())
    room = [[0] * N for i in range(N)]

    for i in range(N):
        instr = input().split()
        for j in range(N):
            room[i][j] = int(instr[j])

    pos_x = 0
    pos_y = 0
    dir = 0 # 0 horiz 1 vert 2 diagonal
    count = [0]

    backtrack(N, pos_x, pos_y, dir, room, count)

    print(count[0])
