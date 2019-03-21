import copy

def move_right(board, N, M, fall):
    for i in range(N):
        temp = ['.']*M
        index = M-1
        hflag = False
        for j in range(M-1, -1, -1):    #역순 검사
            if(board[i][j] == '#'):
                temp[j] = '#'
                index = j - 1
                hflag = False
            elif(board[i][j] == 'O'):
                temp[j] = 'O'
                index = j - 1
                hflag = True
            elif(board[i][j] == 'R'):
                if hflag:
                    fall[0] = 1  #ball fell through
                else:
                    temp[index] = 'R'
                    index = index - 1
            elif(board[i][j] == 'B'):
                if hflag:
                    fall[1] = 1  #ball fell through
                else:
                    temp[index] = 'B'
                    index = index - 1
        for j in range(M):
            board[i][j] = temp[j]

def move_left(board, N, M, fall):
    for i in range(N):
        temp = ['.']*M
        index = 0
        hflag = False
        for j in range(M):    #역순 검사
            if(board[i][j] == '#'):
                temp[j] = '#'
                index = j + 1
                hflag = False
            elif(board[i][j] == 'O'):
                temp[j] = 'O'
                index = j + 1
                hflag = True
            elif(board[i][j] == 'R'):
                if hflag:
                    fall[0] = 1  #ball fell through
                else:
                    temp[index] = 'R'
                    index = index + 1
            elif(board[i][j] == 'B'):
                if hflag:
                    fall[1] = 1  #ball fell through
                else:
                    temp[index] = 'B'
                    index = index + 1
        for j in range(M):
            board[i][j] = temp[j]

def move_down(board, N, M, fall):
    for j in range(M):
        temp = ['.']*N
        index = N-1
        hflag = False
        for i in range(N-1, -1, -1):    #역순 검사
            if(board[i][j] == '#'):
                temp[i] = '#'
                index = i - 1
                hflag = False
            elif(board[i][j] == 'O'):
                temp[i] = 'O'
                index = i - 1
                hflag = True
            elif(board[i][j] == 'R'):
                if hflag:
                    fall[0] = 1  #ball fell through
                else:
                    temp[index] = 'R'
                    index = index - 1
            elif(board[i][j] == 'B'):
                if hflag:
                    fall[1] = 1  #ball fell through
                else:
                    temp[index] = 'B'
                    index = index - 1
        for i in range(N):
            board[i][j] = temp[i]

def move_up(board, N, M, fall):
    for j in range(M):
        temp = ['.']*N
        index = 0
        hflag = False
        for i in range(N):    #역순 검사
            if(board[i][j] == '#'):
                temp[i] = '#'
                index = i + 1
                hflag = False
            elif(board[i][j] == 'O'):
                temp[i] = 'O'
                index = i + 1
                hflag = True
            elif(board[i][j] == 'R'):
                if hflag:
                    fall[0] = 1  #ball fell through
                else:
                    temp[index] = 'R'
                    index = index + 1
            elif(board[i][j] == 'B'):
                if hflag:
                    fall[1] = 1  #ball fell through
                else:
                    temp[index] = 'B'
                    index = index + 1
        for i in range(N):
            board[i][j] = temp[i]

def print_b(board, N, M):
    for i in range(N):
        for j in range(M):
            print(board[i][j], end = "")
        print("")
    print("")

def DFS(board, prev, N, M, iter):
    if(iter > 10 or board == prev):
        return 987654321
    res = [0]*4

    newboard = copy.deepcopy(board)
    fall = [0]*2
    move_up(newboard, N, M, fall)
    if(fall[1] == 1):
        res[0] = 987654321
    elif(fall[0] == 1):
        res[0] = iter + 1
    else:
        res[0] = DFS(newboard, board, N, M, iter+1)
    newboard = copy.deepcopy(board)
    fall = [0]*2
    move_down(newboard, N, M, fall)
    if(fall[1] == 1):
        res[1] = 987654321
    elif(fall[0] == 1):
        res[1] = iter + 1
    else:
        res[1] = DFS(newboard, board, N, M, iter+1)
    newboard = copy.deepcopy(board)
    fall = [0]*2
    move_left(newboard, N, M, fall)
    if(fall[1] == 1):
        res[2] = 987654321
    elif(fall[0] == 1):
        res[2] = iter + 1
    else:
        res[2] = DFS(newboard, board, N, M, iter+1)
    newboard = copy.deepcopy(board)
    fall = [0]*2
    move_right(newboard, N, M, fall)
    if(fall[1] == 1):
        res[3] = 987654321
    elif(fall[0] == 1):
        res[3] = iter + 1
    else:
        res[3] = DFS(newboard, board, N, M, iter+1)
    return min(res)

N, M = map(int, input().strip().split())

board = [[0]*M for i in range(N)]
fall = [0]*2

for i in range(N):
    instr = input()
    for j in range(M):
        board[i][j] = instr[j]

res = DFS(board, [], N, M, 0)
if(res == 987654321):
    print(-1)
else:
    print(res)
'''
print_b(board, N, M)
move_down(board, N, M, fall)
print_b(board, N, M)
print(fall)
'''
