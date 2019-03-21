
def checker(con, bro_init, turn):
    #print(con, bro_init, turn)
    if abs(con-bro_init) <= turn:
        return 1
    elif turn == 0 or bro_init > con:
        return -1

    if con%2 == 0: #even number
        res = checker(int(con/2), bro_init, turn-1)
        if(res == -1):
            return -1
        else:
            return 1
    else:
        res1 = checker(con+1, bro_init, turn-1)
        res2 = checker(con-1, bro_init, turn-1)
        if(res1 == -1 and res2 == -1):
            return -1
        elif(res1 > res2):
            return 1
        else:
            return 1


con, bro = map(int, input().strip().split())

#print(con, brown)
loc = con
conloc = [con]
move = 1
while loc < 200000:
    loc = loc + move
    move = move + 1
    conloc.append(loc)
conloc.pop()    #list of connie's locations up to 200000

index = 0
for i in range(len(conloc)):
    res = checker(conloc[i], bro, i)
    index = i
    if res != -1:
        break
print(index)
