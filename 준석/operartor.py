import copy


def evaluate(N, numbers, current):
    temp = numbers[0]
    for i in range(N-1):
        if current[i] == 0:
            temp = temp + numbers[i+1]
        elif current[i] == 1:
            temp = temp - numbers[i+1]
        elif current[i] == 2:
            temp = temp * numbers[i+1]
        elif current[i] == 3:
            temp = int(temp / numbers[i+1])
    return temp


def backtrack(N, numbers, current, operators, history, index, mini, maxi):

    if index == N - 1:
        res = evaluate(N, numbers, current)
        # print(res)
        if res > maxi[0]:
            maxi[0] = res
        if res < mini[0]:
            mini[0] = res
        return

    n_history = copy.deepcopy(history)
    for i in range(4):
        if operators[i] != 0 and n_history[index][i] == 0:
            n_current = copy.deepcopy(current)
            n_operators = copy.deepcopy(operators)
            n_operators[i] = n_operators[i] - 1
            n_history[index][i] = 1
            n_current[index] = i
            backtrack(N, numbers, n_current, n_operators, n_history, index + 1, mini, maxi)


if __name__ == "__main__":
    N = int(input().strip())
    numbers = [0]*N
    instr = input().strip().split()
    for i in range(N):
        numbers[i] = int(instr[i])

    operators = [0]*4   # + - * /
    instr = input().strip().split()
    for i in range(4):
        operators[i] = int(instr[i])

    history = [[0] * 4 for i in range(N - 1)]  # search history
    current = [0] * (N-1)

    mini = [987654321]
    maxi = [-987654321]

    backtrack(N, numbers, current, operators, history, 0, mini, maxi)

    print(maxi[0])
    print(mini[0])