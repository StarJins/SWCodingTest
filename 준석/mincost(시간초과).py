import copy

N = int(input().strip())
M = int(input().strip())

map = [[987654321]*N for i in range(N)]

for i in range(M):
    instr = input().strip().split()
    map[int(instr[0])-1][int(instr[1])-1] = int(instr[2])
for i in range(N):
    map[i][i] = 0
map = tuple(map)
instr = input().strip().split()
start = int(instr[0]) - 1
end = int(instr[1]) - 1

#print(map)
#What I need to do : Implement dijkstra
to_visit = []
visited = []
distance_guess = copy.deepcopy(map[start])

for i in range(N):
    if i == start:
        visited.append(i)
    else:
        to_visit.append(i)

while len(to_visit) != 0:
    min = 987654321
    ind = -1
    for i in range(len(to_visit)):
        if distance_guess[to_visit[i]] < min:
            min = distance_guess[to_visit[i]]
            ind = i
    index = to_visit[ind]   #next node to visit
    del to_visit[ind]
    for i in range(N):
        if distance_guess[i] > distance_guess[index] + map[index][i]:
            distance_guess[i] = distance_guess[index] + map[index][i]
    visited.append(index)
    if(index == end):
        break

print(distance_guess[end])
