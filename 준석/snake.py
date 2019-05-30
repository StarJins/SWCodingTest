from collections import namedtuple

point = namedtuple("point", "x y")
dx = [0, -1, 0, 1]
dy = [1, 0, -1, 0]


def move(board, snake, head, direction):
    new_x = head[0].x + dx[direction]
    new_y = head[0].y + dy[direction]

    if board[new_x][new_y] == 3 or board[new_x][new_y] == 1:
        # print("Death cause = ", board[new_x][new_y])
        return -1   # snake is dead

    head[0] = point(new_x, new_y)
    if board[new_x][new_y] == 0:
        prev = snake.pop(0)
        board[prev.x][prev.y] = 0

    board[new_x][new_y] = 1
    snake.append(head[0])
    return 0


def change_dir(direction, C):
    if C == 'L':
        if direction < 3:
            return direction + 1
        else:
            return 0
    else:
        if direction > 0:
            return direction - 1
        else:
            return 3


def print_board(board, N):
    N = N + 2
    for i in range(N):
        for j in range(N):
            print(board[i][j], end=" ")
        print("")
    print("")

if __name__ == "__main__":
    N = int(input().strip())
    board = [[0]*(N+2) for i in range(N+2)]

    for i in range(N+2):
        for j in range(N+2):
            if i == 0 or i == N+1 or j == 0 or j == N+1:
                board[i][j] = 3
    # 3 for denoting walls

    apples = int(input().strip())
    for i in range(apples):
        x, y = map(int, input().strip().split())
        board[x][y] = 2
    # 2 for denoting apples

    snake = [point(1, 1)]
    head = [point(1, 1)]
    board[1][1] = 1
    # 1 for denoting snake body
    direction = 0
    # direction 0 1 2 3  right up left down

    moves = int(input().strip())
    counter = 0
    time = []
    C = []
    index = 0
    for i in range(moves):
        instr = input().strip().split()
        time.append(int(instr[0]))
        C.append(instr[1])

    while True:
        if index < len(time) and counter == time[index]:
            direction = change_dir(direction, C[index])
            index = index + 1
            continue

        counter = counter + 1
        if move(board, snake, head, direction) == -1:
            break
        # print("count = ", counter, "direction = ", direction)
        # print_board(board, N)

    print(counter)