

def get_hit(h, dmg):
    temp = h - dmg
    if temp < 0:
        return 0
    else:
        return temp

def solve(dp, a, b, c, x):
    if a == b == c == 0:
        dp[a][b][c] = x
        return x
    if dp[a][b][c] != -1:
        return dp[a][b][c]

    res = [987654321]*6
    if a > 0:
        res[0] = solve(dp, get_hit(a, 9), get_hit(b, 3), get_hit(c, 1), x+1)
        res[1] = solve(dp, get_hit(a, 9), get_hit(b, 1), get_hit(c, 3), x+1)
    if b > 0:
        res[2] = solve(dp, get_hit(a, 3), get_hit(b, 9), get_hit(c, 1), x+1)
        res[3] = solve(dp, get_hit(a, 1), get_hit(b, 9), get_hit(c, 3), x+1)
    if c > 0:
        res[4] = solve(dp, get_hit(a, 1), get_hit(b, 3), get_hit(c, 9), x+1)
        res[5] = solve(dp, get_hit(a, 3), get_hit(b, 1), get_hit(c, 9), x+1)
    dp[a][b][c] = min(res)
    return dp[a][b][c]


if __name__ == "__main__":
    N = int(input().strip())
    instr = input().strip().split()
    scv = [0] * 3
    for i in range(N):
       scv[i] = int(instr[i])

    # dp[체력1][2][3]
    dp = [[[-1]*61 for i in range(61)] for j in range(61)]

    print(solve(dp, scv[0], scv[1], scv[2], 0))
