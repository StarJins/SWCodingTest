

def solve(dp, row, col, rook):
    if rook == 0:
        return 1
    elif row == 0 or col == 0: # 룩이 남았지만 공간이 안 남은 경우
        return 0

    if dp[row][col][rook] != -1:
        return dp[row][col][rook]

    # 4가지 case : 2개를 같은열, 열에 하나만 넣고 이후 같은행에 배치, 행/열에 하나만 배치, 이 행에는 안 배치
    res = [0] * 4
    if row > 1 and col > 0 and rook > 1:
        res[0] = int(solve(dp, row-2, col-1, rook-2) * row * (row-1) / 2)
    if row > 0 and col > 1 and rook > 1:
        res[1] = solve(dp, row-1, col-2, rook-2) * row * (col-1)
    if row > 0 and col > 0 and rook > 0:
        res[2] = solve(dp, row-1, col-1, rook-1) * row
    if col > 0:
        res[3] = solve(dp, row, col - 1, rook)

    dp[row][col][rook] = sum(res)
    return dp[row][col][rook]


if __name__ == "__main__":
    N = int(input().strip())
    M = int(input().strip())
    K = int(input().strip())

    dp = [[[-1] * (K+1) for i in range(M + 1)] for j in range(N + 1)]
    # dp[남은 행][남은 열][남은 룩]
    print(solve(dp, N, M, K)%1000001)