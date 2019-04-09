

def solve(dp, string, N, K, x, a, b, n):
    if x == N:  # base case
        if n == K:
            return True
        else:
            return False

    # 방문한 곳을 다시 방문 == 문자열이 없음
    if dp[x][a][b][n]:
        return False

    # 방문한 곳을 표시
    dp[x][a][b][n] == True

    # ABC 3가지 경우에 대해 재귀호출
    string[x] = 'A'
    if solve(dp, string, N, K, x+1, a+1, b, n):
        return True

    string[x] = 'B'
    if solve(dp, string, N, K, x+1, a, b+1, n + a):
        return True

    string[x] = 'C'
    if solve(dp, string, N, K, x+1, a, b, n + a + b):
        return True
    # 답이 안나왔으면 False 반환
    return False


def print_str(string):
    for i in range(30):
        if string[i] != '':
            print(string[i], end = "")
        else:
            break


if __name__ == "__main__":

    N, K = map(int, input().strip().split())

    dp = [[[[False] * 436 for i in range(31)] for j in range(31)] for k in range(31)]
    string = ['']*30

    if solve(dp, string, N, K, 0, 0, 0, 0):
        print_str(string)
    else:
        print(-1)

