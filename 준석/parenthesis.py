import copy


def backtrack(n2, chosen, index, nums, operators, gmax):
    if index == n2: # base case: calculations

        nnums = []
        nop = []
        count = 0

        for i in range(n2):
            if chosen[i] == 1:
                count += 1
                if operators[i] == '*':
                    nnums.append(nums[i] * nums[i+1])
                elif operators[i] == '+':
                    nnums.append(nums[i] + nums[i+1])
                else:   # minus case
                    nnums.append(nums[i] - nums[i+1])
            else:
                nop.append(operators[i])
                if count == 0:
                    nnums.append(nums[i])
                elif i == n2 - 1 or (i < n2-1 and chosen[i+1] != 1):
                    nnums.append(nums[i + 1])
        if count == 0:
            nnums.append(nums[len(nums)-1])

        # print(nnums, nop, chosen)
        res = nnums[0]
        for i in range(len(nop)):
            if nop[i] == '*':
                res = res * nnums[i+1]
            elif nop[i] == '+':
                res = res + nnums[i+1]
            else:  # minus case
                res = res - nnums[i+1]

        if res > gmax[0]:
            gmax[0] = res
        return

    ncho = copy.deepcopy(chosen)

    backtrack(n2, ncho, index + 1, nums, operators, gmax) # not chosen case: always done
    if chosen[index] == 0:  #no markings
        ncho[index] = 1
        if index < n2 - 1:
            ncho[index + 1] = -1
        backtrack(n2, ncho, index + 1, nums, operators, gmax)


if __name__ == "__main__":
    N = int(input())
    line = input()
    N1 = int((N + 1) / 2)
    N2 = int((N - 1) / 2)
    nums = [0] * N1
    operators = [''] * N2
    chosen = [0] * N2
    gmax = [-987654321]

    for i in range(len(line)):
        if i%2 == 0:
            nums[int(i/2)] = int(line[i])
        else:
            operators[int(i/2)] = line[i]

    # print(nums)
    # print(operators)

    backtrack(N2, chosen, 0, nums, operators, gmax)

    print(gmax[0])
