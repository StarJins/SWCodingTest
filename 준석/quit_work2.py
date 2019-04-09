
if __name__ == "__main__":
    N = int(input())

    meetings = [[0] * 2 for i in range(N)]
    for i in range(N):
        meetings[i][0], meetings[i][1] = map(int, input().split())

    dp = [0] * N
    maxi = 0

    for i in range(N-1, -1, -1):
        a = meetings[i][0]  # 걸리는 시간
        b = meetings[i][1]  # 버는 돈

        if a > N - i:  # 일이 기한을 넘어가면 스킵
            continue

        temp = b   # 오늘부터 시작되는 일을 했을때 얻는 이득
        if a + i < N:
            temp = temp + dp[a + i]

        # 오늘 일을 안했을때의 이득과 비교, 최댓값 구하기
        if temp > maxi:
            maxi = temp
        else:
            temp = maxi

        dp[i] = temp

    print(maxi)
