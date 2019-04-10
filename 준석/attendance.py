

def calc(n):
    if n == 0:
        return 0
    else:
        return n-1


def solve(N, string, dp, a, b, c, bp, cp, x):
    if N == x:
        return True
    if dp[a][b][c][bp][cp][x]:
        return False
    dp[a][b][c][bp][cp][x] = True

    if cp == 0 and c > 0:
        string[x] = 'C'
        if solve(N, string, dp, a, b, c-1, calc(bp), 2, x+1):
            return True
    if bp == 0 and b > 0:
        string[x] = 'B'
        if solve(N, string, dp, a, b-1, c, 1, calc(cp), x+1):
            return True
    if a > 0:
        string[x] = 'A'
        if solve(N, string, dp, a-1, b, c, calc(bp), calc(cp), x+1):
            return True
    return False

if __name__ == "__main__":
    instr = input()
    N = len(instr)
    abc = [0] * 3
    for i in range(N):
        if instr[i] == 'A':
            abc[0] = abc[0] + 1
        elif instr[i] == 'B':
            abc[1] = abc[1] + 1
        else:
            abc[2] = abc[2] + 1

    # dp[51][51][51][2][3][51]
    dp = [[[[[[False] * (N+1) for i in range(3)] for j in range(2)] for k in range(N+1)] for l in range(N+1)] for m in range(N+1)]
    string = [''] * N

    if solve(N, string, dp, abc[0], abc[1], abc[2], 0, 0, 0):
        print("".join(string))
    else:
        print(-1)
