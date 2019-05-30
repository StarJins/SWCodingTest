

def solve(dp, M, P, x, S, U):
    if x == P:
        if U == 0:
            return 1
        else:
            return 0
    if dp[x][S][U] != -1:
        return dp[x][S][U]

    res = [0]*2

    # 아직 선택 안한 곡을 선택
    if U > 0:
        res[0] = solve(dp, M, P, x+1, S+1, U-1) * U

    # 선택했던 곡을 재선택
    if S > M:
        res[1] = solve(dp, M, P, x+1, S, U) * (S - M)

    dp[x][S][U] = sum(res)
    return dp[x][S][U]


if __name__ == "__main__":
    N, M, P = map(int, input().strip().split())

    dp = [[[-1]* 101 for i in range(101)] for j in range(101)]
    # dp[x][S][N]: 현재까지 선택된 곡 S 갯수 선택 안된곡 N

    print(solve(dp, M, P, 0, 0, N)%1000000007)
