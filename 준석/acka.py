

def solve(dp, x, a, b, c):
    if dp[x][a][b][c] != -1:
        return dp[x][a][b][c]

    if x == 0:
        if a == b == c == 0:
            return 1
        else:
            return 0

    res = [0] * 7
    for i in range(7):
        n = i + 1
        d = n%2
        e = int(n/2)%2
        f = int(n/4)%2
        if a-d < 0 or b-e<0 or c-f<0:
            continue
        else:
            res[i] = solve(dp, x-1, a-d, b-e, c-f)
    dp[x][a][b][c] = sum(res)
    return dp[x][a][b][c]


if __name__ == "__main__":
    instr = input().strip().split()

    N = int(instr[0])
    ppl = [0] * 3
    for i in range(3):
        ppl[i] = int(instr[i+1])

    dp = [[[[-1]* (N+1) for i in range(N+1)] for j in range(N+1)] for k in range(N+1)]

    if sum(ppl) < N:
        print(0)
    else:
        print(solve(dp, N, ppl[0], ppl[1], ppl[2]) % 1000000007)
