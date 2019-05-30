

def intfunc(intensity):
    if 0 <= intensity < 510000:
        return '#'
    elif intensity < 1020000:
        return 'o'
    elif intensity < 1530000:
        return '+'
    elif intensity < 2040000:
        return '-'
    else:
        return '.'


if __name__ == "__main__":
    N, M = map(int, input().strip().split())
    image = [[0]*M for i in range(N)]
    for i in range(N):
        instr = input().strip().split()
        for j in range(M):
            a1 = 3 * j
            a2 = a1 + 1
            a3 = a2 + 1
            intensity = 2126 * int(instr[a1]) + 7152 * int(instr[a2]) + 722 * int(instr[a3])
            image[i][j] = intfunc(intensity)

    for i in range(N):
        for j in range(M):
            print(image[i][j], end = "")
        print("")