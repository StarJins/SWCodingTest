def Down():
    temp = position["top"];
    position["top"] = position["back"];
    position["back"] = position["bottom"];
    position["bottom"] = position["front"];
    position["front"] = temp;

def Up():
    temp = position["top"];
    position["top"] = position["front"];
    position["front"] = position["bottom"];
    position["bottom"] = position["back"];
    position["back"] = temp;

def Left():
    temp = position["top"];
    position["top"] = position["right"];
    position["right"] = position["bottom"];
    position["bottom"] = position["left"];
    position["left"] = temp;

def Right():
    temp = position["top"];
    position["top"] = position["left"];
    position["left"] = position["bottom"];
    position["bottom"] = position["right"];
    position["right"] = temp;


def IsValid(d):
    nx = xy[0] + dx[d];
    ny = xy[1] + dy[d];

    if (nx < 0 or nx >= n):
        return True;
    if (ny < 0 or ny >= m):
        return True;

    return False;

def Check():
    if (map[xy[0]][xy[1]] == 0):
        map[xy[0]][xy[1]] = dice[position["bottom"]];
    else:
        dice[position["bottom"]] = map[xy[0]][xy[1]];
        map[xy[0]][xy[1]] = 0;

    print(dice[position["top"]]);

# 기본 입력
n, m, x, y, k = input().split();
n = int(n);
m = int(m);
x = int(x);
y = int(y);
xy = [x, y];
k = int(k);

# 맵과 주사위 설정, 주사위는 indexing이 편하게 7개 설정
map = [[0 for cols in range(m)]for rows in range(n)];
dice = [0] * 7;

# 맵 입력
for i in range(n):
    tmp = input().split();
    for j in range(m):
        map[i][j] = int(tmp[j]);

# 이동 명령 입력
go = input().split();

# 주사위 기본 위치 입력
position = {"dump":0, "top":1, "back":2, "right":3, "left":4, "front":5, "bottom":6};

# 방향함수도 편의성을 위해 index 0은 사용 X
dx = [0, 0, 0, -1, 1];
dy = [0, 1, -1, 0, 0];

# 주사위 이동 시작
for i in range(k):
    direction = int(go[i]);
    if (direction == 1):
        if(IsValid(direction) == False):
            xy[0] = xy[0] + dx[direction];
            xy[1] = xy[1] + dy[direction];
            Right();
            Check();
        else:
            continue;
    elif (direction == 2):
        if(IsValid(direction) == False):
            xy[0] = xy[0] + dx[direction];
            xy[1] = xy[1] + dy[direction];
            Left();
            Check();
        else:
            continue;
    elif (direction == 3):
        if(IsValid(direction) == False):
            xy[0] = xy[0] + dx[direction];
            xy[1] = xy[1] + dy[direction];
            Up();
            Check();
        else:
            continue;
    else:
        if(IsValid(direction) == False):
            xy[0] = xy[0] + dx[direction];
            xy[1] = xy[1] + dy[direction];
            Down();
            Check();
        else:
            continue;
