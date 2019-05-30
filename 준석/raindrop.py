# import random

if __name__ == "__main__":
    N, W = map(int, input().split())
    degree = [0] * (N + 1)
    for i in range(N - 1):
        a, b = map(int, input().split())
        degree[a] += 1
        degree[b] += 1
    print(W / degree.count(1))

    '''
    for i in range(N-1):
        a, b = map(int, input().strip().split())
        if a > b:
            temp = a
            a = b
            b = temp
        tree[a-1].append(b-1)

    leaf = 0
    for i in range(N):
        if len(tree[i]) == 1:
            leaf = leaf + 1
    if leaf < W:
        print(W/leaf)
        exit(0)

    flag = True
    while flag:
        flag = False
        factor = random.randint(0, 1)

        for i in range(N-1, -1, -1):
            if tree[i][0] == 0:     # no water
                continue
            children = len(tree[i]) - 1
            if children == 0:   # no children
                continue
            elif children == 1:
                chosen = tree[i][1]
            else:
                chosen = tree[i][factor + 1]
            tree[i][0] = tree[i][0] - 1
            tree[chosen][0] = tree[chosen][0] + 1
            flag = True
    
    if num == 0:
        print(0)
    else:
        print(add/num)
    '''
