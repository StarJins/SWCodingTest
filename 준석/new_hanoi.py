import copy


if __name__ == "__main__":
    tower = [[] for i in range(4)]
    for i in range(3):
        instr = input().split(" ")
        n = int(instr[0])
        for j in range(n):
            tower[i].append(instr[1][j])
    tower[3] = [0]

    to_visit = []
    to_visit.append(tower)
    visited = []
    visited.append(tower)
    depth = 0

    while True:
        state = to_visit.pop(0)
        fix = [True] * 3
        for i in range(3):
            for j in range(len(state[i])):
                if state[i][j] != chr(ord('A') + i):
                    fix[i] = False
                    break
        if fix[0] and fix[1] and fix[2]:    # end search
            depth = state[3][0]
            break

        if not fix[0] and len(state[0]) > 0:
            new_s = copy.deepcopy(state)
            new_s[1].append(new_s[0].pop())
            new_s[3][0] = state[3][0] + 1
            to_visit.append(new_s)
            new_s2 = copy.deepcopy(state)
            new_s2[2].append(new_s2[0].pop())
            new_s2[3][0] = state[3][0] + 1
            to_visit.append(new_s2)
        if not fix[1] and len(state[1]) > 0:
            new_s = copy.deepcopy(state)
            new_s[0].append(new_s[1].pop())
            new_s[3][0] = state[3][0] + 1
            to_visit.append(new_s)
            new_s2 = copy.deepcopy(state)
            new_s2[2].append(new_s2[1].pop())
            new_s2[3][0] = state[3][0] + 1
            to_visit.append(new_s2)
        if not fix[2] and len(state[2]) > 0:
            new_s = copy.deepcopy(state)
            new_s[1].append(new_s[2].pop())
            new_s[3][0] = state[3][0] + 1
            to_visit.append(new_s)
            new_s2 = copy.deepcopy(state)
            new_s2[0].append(new_s2[2].pop())
            new_s2[3][0] = state[3][0] + 1
            to_visit.append(new_s2)

    print(depth)
