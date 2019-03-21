
from collections import namedtuple
#좌표 구조체


def move_up(map, N, M, dice, current):
    if(current['x'] == 0):
        return #OB: do nothing
    current['x'] = current['x'] - 1
    temp = dice[4]
    dice[4] = dice[0]
    dice[0] = dice[5]
    dice[5] = dice[2]
    dice[2] = temp
    if(map[current['x']][current['y']] == 0):
        map[current['x']][current['y']] = dice[2]
    else:
        dice[2] = map[current['x']][current['y']]
        map[current['x']][current['y']] = 0
    print(dice[0])

def move_down(map, N, M, dice, current):
    if(current['x'] == N - 1):
        return #OB: do nothing
    current['x'] = current['x'] + 1
    temp = dice[4]
    dice[4] = dice[2]
    dice[2] = dice[5]
    dice[5] = dice[0]
    dice[0] = temp
    if(map[current['x']][current['y']] == 0):
        map[current['x']][current['y']] = dice[2]
    else:
        dice[2] = map[current['x']][current['y']]
        map[current['x']][current['y']] = 0
    print(dice[0])

def move_left(map, N, M, dice, current):
    if(current['y'] == 0):
        return #OB: do nothing
    current['y'] = current['y'] - 1
    temp = dice[3]
    dice[3] = dice[0]
    dice[0] = dice[1]
    dice[1] = dice[2]
    dice[2] = temp
    if(map[current['x']][current['y']] == 0):
        map[current['x']][current['y']] = dice[2]
    else:
        dice[2] = map[current['x']][current['y']]
        map[current['x']][current['y']] = 0
    print(dice[0])

def move_right(map, N, M, dice, current):
    if(current['y'] == M-1):
        return #OB: do nothing
    current['y'] = current['y'] + 1
    temp = dice[1]
    dice[1] = dice[0]
    dice[0] = dice[3]
    dice[3] = dice[2]
    dice[2] = temp
    if(map[current['x']][current['y']] == 0):
        map[current['x']][current['y']] = dice[2]
    else:
        dice[2] = map[current['x']][current['y']]
        map[current['x']][current['y']] = 0
    print(dice[0])


#기본 입력
instr = input().strip().split()

N = int(instr[0])
M = int(instr[1])

map = [[0]* M for i in range(N)]

position = {'x':int(instr[2]), 'y':int(instr[3])}
movecnt = int(instr[4])

for i in range(N):
    instr = input().strip().split()
    for j in range(M):
        map[i][j] = int(instr[j])

instr = input().strip().split()
#주사위
dice = [0]*6
'''
이해를 위한 전개도 예시:
dice[0] = 1 #상
dice[1] = 3 #우
dice[2] = 6 #하
dice[3] = 4 #좌
dice[4] = 2 #전
dice[5] = 5 #후
'''

for i in range(len(instr)):
    if(instr[i] == '1'):
        move_right(map, N, M, dice, position)
    elif(instr[i] == '2'):
        move_left(map, N, M, dice, position)
    elif(instr[i] == '3'):
        move_up(map, N, M, dice, position)
    elif(instr[i] == '4'):
        move_down(map, N, M, dice, position)
    else:
        continue

#print(initpoint)
