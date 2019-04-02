import copy

# 한 면의 회전 - 시계방향
def turn_sideR(cube, s):
    temp1 = ['a']*3
    temp2 = ['a']*3
    temp3 = ['a'] * 3
    temp4 = ['a'] * 3
    for i in range(3):
        temp1[i] = cube[s][0][i]
        temp2[i] = cube[s][2][i]
        temp3[i] = cube[s][2 - i][0]
        temp4[i] = cube[s][2 - i][2]
    for i in range(3):
        cube[s][0][i] = temp3[i]
        cube[s][2][i] = temp4[i]
        cube[s][i][0] = temp2[i]
        cube[s][i][2] = temp1[i]


#한 면의 회전 - 반시계방향
def turn_sideL(cube, s):
    temp1 = ['a'] * 3
    temp2 = ['a'] * 3
    temp3 = ['a'] * 3
    temp4 = ['a'] * 3
    for i in range(3):
        temp1[i] = cube[s][0][i]
        temp2[i] = cube[s][2][i]
        temp3[i] = cube[s][i][2]
        temp4[i] = cube[s][i][0]
    for i in range(3):
        cube[s][0][i] = temp3[i]
        cube[s][2][i] = temp4[i]
        cube[s][i][0] = temp1[2-i]
        cube[s][i][2] = temp2[2-i]


#수평회전, ind 0/2로 위 아래 구분
def turn_hor(cube, ind, s1, s2, s3, s4):
    temp = ['a']*3
    for i in range(3):
        temp[i] = cube[s1][ind][i]
    for i in range(3):
        cube[s1][ind][i] = cube[s2][ind][i]
        cube[s2][ind][i] = cube[s3][ind][i]
        cube[s3][ind][i] = cube[s4][ind][i]
        cube[s4][ind][i] = temp[i]


#정면 수직회전, 시계
def turn_vert_fb1(cube, ind, s1, s2):
    temp = ['a'] * 3
    top = 0
    down = 1
    for i in range(3):
        temp[i] = cube[top][ind][i]
    for i in range(3):
        cube[top][ind][i] = cube[s1][2-i][2]
    for i in range(3):
        cube[s1][i][2] = cube[down][2-ind][i]
    for i in range(3):
        cube[down][2 - ind][i] = cube[s2][2-i][0]
    for i in range(3):
        cube[s2][i][0] = temp[i]


#정면 수직회전, 반시계
def turn_vert_fb2(cube, ind, s1, s2):
    temp = ['a'] * 3
    top = 0
    down = 1
    for i in range(3):
        temp[i] = cube[top][ind][i]
    for i in range(3):
        cube[top][ind][i] = cube[s2][i][0]
    for i in range(3):
        cube[s2][i][0] = cube[down][2-ind][2-i]
    for i in range(3):
        cube[down][2 - ind][i] = cube[s1][i][2]
    for i in range(3):
        cube[s1][i][2] = temp[2-i]


#측면 수직회전, 시계(오른쪽 기준)
def turn_vert_s1(cube, ind, s1, s2):
    temp = ['a'] * 3
    top = 0
    down = 1
    for i in range(3):
        temp[i] = cube[top][i][ind]
    for i in range(3):
        cube[top][i][ind] = cube[s1][i][ind]
    for i in range(3):
        cube[s1][i][ind] = cube[down][i][ind]
    for i in range(3):
        cube[down][i][ind] = cube[s2][2-i][2-ind]
    for i in range(3):
        cube[s2][2 - i][2 - ind] = temp[i]


#측면 수직회전, 반시계(오른쪽 기준)
def turn_vert_s2(cube, ind, s1, s2):
    temp = ['a'] * 3
    top = 0
    down = 1
    for i in range(3):
        temp[i] = cube[top][i][ind]
    for i in range(3):
        cube[top][i][ind] = cube[s2][2-i][2-ind]
    for i in range(3):
        cube[s2][2-i][2-ind] = cube[down][i][ind]
    for i in range(3):
        cube[down][i][ind] = cube[s1][i][ind]
    for i in range(3):
        cube[s1][i][ind] = temp[i]


def print_top(cube):
    for i in range(3):
        for j in range(3):
            print(cube[0][i][j], end = "")
        print("")


if __name__ == "__main__":
    cases = int(input().strip())
    N = []
    instr = []

    # A notation on side-number scheme
    top = 0
    down = 1
    front = 2
    back = 3
    left = 4
    right = 5

    ins = []
    for h in range(cases):
        N = int(input().strip())
        ins = input().strip().split(" ")
        instr.append(ins)

    for h in range(cases):
        cube = []
        cube.append([['w'] * 3 for i in range(3)])
        cube.append([['y'] * 3 for i in range(3)])
        cube.append([['r'] * 3 for i in range(3)])
        cube.append([['o'] * 3 for i in range(3)])
        cube.append([['g'] * 3 for i in range(3)])
        cube.append([['b'] * 3 for i in range(3)])

        for i in range(len(instr[h])):
            if instr[h][i] == "U+":
                turn_sideR(cube, top)
                turn_hor(cube, 0, front, right, back, left)
            elif instr[h][i] == "U-":
                turn_sideL(cube, top)
                turn_hor(cube, 0, front, left, back, right)
            elif instr[h][i] == "D+":
                turn_sideR(cube, down)
                turn_hor(cube, 2, front, left, back, right)
            elif instr[h][i] == "D-":
                turn_sideL(cube, down)
                turn_hor(cube, 2, front, right, back, left)
            elif instr[h][i] == "F+":
                turn_sideR(cube, front)
                turn_vert_fb1(cube, 2, left, right)
            elif instr[h][i] == "F-":
                turn_sideL(cube, front)
                turn_vert_fb2(cube, 2, left, right)
            elif instr[h][i] == "B+":
                turn_sideR(cube, back)
                turn_vert_fb1(cube, 0, right, left)
            elif instr[h][i] == "B-":
                turn_sideL(cube, back)
                turn_vert_fb2(cube, 0, right, left)
            elif instr[h][i] == "L+":
                turn_sideR(cube, left)
                turn_vert_s2(cube, 0, front, back)
            elif instr[h][i] == "L-":
                turn_sideL(cube, left)
                turn_vert_s1(cube, 0, front, back)
            elif instr[h][i] == "R+":
                turn_sideR(cube, right)
                turn_vert_s1(cube, 2, front, back)
            elif instr[h][i] == "R-":
                turn_sideL(cube, right)
                turn_vert_s2(cube, 2, front, back)

        print_top(cube)
