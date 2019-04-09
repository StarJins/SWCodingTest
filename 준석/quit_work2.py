
def solve(meetings, N, dp, x):

    if x > N:
        return -987654321
    if x == N:
        return 0
    if dp[x] != -1:
        return dp[x]

    a = meetings[x][0]  # 시간
    b = meetings[x][1]  # 돈

    dp[x] = max((solve(meetings, N, dp, x + a) + b), (solve(meetings, N, dp, x + 1)))
    return dp[x]


if __name__ == "__main__":
    N = int(input())

    meetings = [[0] * 2 for i in range(N)]
    for i in range(N):
        meetings[i][0], meetings[i][1] = map(int, input().split())

    dp = [-1] * N

    print(solve(meetings, N, dp, 0))
    
