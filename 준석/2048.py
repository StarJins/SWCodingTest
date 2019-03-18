import copy

def move_right(board, n):
    for i in range(n):  #일단 한 행씩
        temprow = [0]*n
        tempindex = n-1
        for j in range(n-1, -1, -1):  #역순 검사
            #print(tempindex)
            if(board[i][j] == 0):
                continue
            elif(temprow[tempindex] == 0):  #비어있음 = 삽입
                temprow[tempindex] = board[i][j]
            elif(temprow[tempindex] != board[i][j]):    #다른 수 = 다음 칸에 삽입
                tempindex = tempindex - 1
                temprow[tempindex] = board[i][j]
            else:   #같은 수 = 더하고 인덱스 옮김
                temprow[tempindex] = temprow[tempindex]*2
                tempindex = tempindex - 1
        #한 행이 끝나면 덮어쓰기
        for j in range(n):
            board[i][j] = temprow[j]

def move_left(board, n):
    for i in range(n):  #일단 한 행씩
        temprow = [0]*n
        tempindex = 0
        for j in range(n):  # 검사
            #print(tempindex)
            if(board[i][j] == 0):
                continue
            elif(temprow[tempindex] == 0):  #비어있음 = 삽입
                temprow[tempindex] = board[i][j]
            elif(temprow[tempindex] != board[i][j]):    #다른 수 = 다음 칸에 삽입
                tempindex = tempindex + 1
                temprow[tempindex] = board[i][j]
            else:   #같은 수 = 더하고 인덱스 옮김
                temprow[tempindex] = temprow[tempindex]*2
                tempindex = tempindex + 1
        #한 행이 끝나면 덮어쓰기
        for j in range(n):
            board[i][j] = temprow[j]

def move_down(board, n):
    for j in range(n):  #일단 한 열씩
        tempcol = [0]*n
        tempindex = n-1
        for i in range(n-1, -1, -1):  #역순 검사
            if(board[i][j] == 0):
                continue
            elif(tempcol[tempindex] == 0):  #비어있음 = 삽입
                tempcol[tempindex] = board[i][j]
            elif(tempcol[tempindex] != board[i][j]):    #다른 수 = 다음 칸에 삽입
                tempindex = tempindex - 1
                tempcol[tempindex] = board[i][j]
            else:   #같은 수 = 더하고 인덱스 옮김
                tempcol[tempindex] = tempcol[tempindex]*2
                tempindex = tempindex - 1
        #한 행이 끝나면 덮어쓰기
        for i in range(n):
            board[i][j] = tempcol[i]

def move_up(board, n):
    for j in range(n):  #일단 한 열씩
        tempcol = [0]*n
        tempindex = 0
        for i in range(n):  # 검사
            if(board[i][j] == 0):
                continue
            elif(tempcol[tempindex] == 0):  #비어있음 = 삽입
                tempcol[tempindex] = board[i][j]
            elif(tempcol[tempindex] != board[i][j]):    #다른 수 = 다음 칸에 삽입
                tempindex = tempindex + 1
                tempcol[tempindex] = board[i][j]
            else:   #같은 수 = 더하고 인덱스 옮김
                tempcol[tempindex] = tempcol[tempindex]*2
                tempindex = tempindex + 1
        #한 행이 끝나면 덮어쓰기
        for i in range(n):
            board[i][j] = tempcol[i]

def DFS(board, prev, n, iter):
    if(iter == 5 or board == prev):#재귀호출 종료. 이전 과 같은 경우는 prune tree.
        max = 0
        for i in range(n):
            for j in range(n):
                if(board[i][j] > max):
                    max = board[i][j]
        return max
    else:   #4가지 방향으로 움직임 각각 재귀호출 후 반환값 비교
        res = [0]*4
        newboard = copy.deepcopy(board)
        move_up(newboard, n)
        res[0] = DFS(newboard, board, n, iter+1)
        newboard = copy.deepcopy(board)
        move_down(newboard, n)
        res[1] = DFS(newboard, board, n, iter+1)
        newboard = copy.deepcopy(board)
        move_left(newboard, n)
        res[2] = DFS(newboard, board, n, iter+1)
        newboard = copy.deepcopy(board)
        move_right(newboard, n)
        res[3] = DFS(newboard, board, n, iter+1)
        max = 0
        for i in range(4):
            if(max < res[i]):
                max = res[i]
        return max

instr = input()

N = int(instr)

board = [[0]*N for i in range(N)]
dummy = [[0]*N for i in range(N)]

for i in range(N):
    instr = input()
    inspl = instr.split()
    for j in range(N):
        board[i][j] = int(inspl[j])
#print(board)
print(DFS(board, dummy, N, 0))
