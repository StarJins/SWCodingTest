teams = list(input().split(' '))
teams_dict = dict()
for team in teams:
    teams_dict[team] = float()

for step in range(6):
    a, b, w, d, l = input().split(' ')
    w, d, l = float(w), float(d), float(l)

    teams_dict[a] += w*3 + d*1 + l*0
    teams_dict[b] += w*0 + d*1 + l*3

# sorted by cal result
teams_list = sorted(teams_dict.items(), key = lambda x : x[1], reverse=True)

names = [x[0] for x in teams_list]
scores = [x[1] for x in teams_list]
answer = list()

# pass possibility
# 1 2 2 4 -> 1.0 0.5 0.5 0
if scores.count(scores[1]) == 2:
    answer.append(1.0)
    for step in range(2):
        answer.append(0.5)
    answer.append(0.0)

# 1 2 2 2 -> 1.0 0.33 0.33 0.33
elif scores.count(scores[1]) == 3:
    answer.append(1.0)
    for step in range(3):
        answer.append(0.33)

# 1 1 3 3 -> 0.5 0.5 0 0
elif scores.count(scores[0]) == 2 and scores.count(scores[2]) == 2:
    for step in range(2):
        answer.append(0.5)
    for step in range(2):
        answer.append(0.0)

# 1 1 1 4 -> 0.66 0.66 0.66 0
elif scores.count(scores[0]) == 3:
    for step in range(3):
        answer.append(0.5)
    answer.append(0.0)

# 1 1 1 1 -> 0.5 0.5 0.5 0.5
elif scores.count(scores[0]) == 4:
    for step in range(4):
        answer.append(0.5)

# 1 2 3 4, 1 2 3 3 -> 1.0 1.0 0 0
else:
    for step in range(2):
        answer.append(1.0)
    for step in range(2):
        answer.append(0.0)

teams_dict.clear()
for i in range(4):
    teams_dict[names[i]] = answer[i]

for x in teams:
    print('%.10f' % teams_dict[x])