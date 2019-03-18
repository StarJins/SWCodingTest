import math

#a, b = map(int, input().strip().split(' '))
#print(a + b)

instr = input().strip().split(' ')
N = int(instr[0])
root_n = math.sqrt(N)
floored_root = math.floor(root_n)

min = N

for i in range(1, floored_root+1):  #test up to root of N
    if(N%i == 0):
        min = int(N/i) - i

print(min)

===============



#a, b = map(int, input().strip().split(' '))
#print(a + b)

#a, b = map(int, input().strip().split(' '))
#print(a + b)

instr = input()

numbers = set(['0', '1', '2', '3', '4', '5', '6', '7', '8', '9'])
capitals = set(['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'])
str1 = ""
str2 = ""
strc = ""
for i in range(len(instr)):
    if(instr[i] in numbers):#divide letters from numbers
        str2 += instr[i]
    else:
        str1 += instr[i]
    if(instr[i] in capitals):
        strc += instr[i]


if(len(strc) != len(str2)):#error case
    print("error")
else:
    j = 0
    for i in range(len(strc)):
        if(str2[i] == '1'):
            print(strc[i], end="")
            if(len(str1) >= j+2 and str1[j+1] not in capitals):
                print(str1[j+1], end="")
                j = j + 1
        else:
            print(strc[i], end="")
            if(len(str1) >= j+2 and str1[j+1] not in capitals):
                print(str1[j+1], end="")
                j = j + 1
            print(str2[i], end="")
        j = j + 1
print("")


==============


#a, b = map(int, input().strip().split(' '))
#print(a + b)

n = int(input())
a = {1:0}#dictionary for val
del a[1]
s1 = set()#set of id
header1 = input().strip().split()
for i in range(n-1):
    instr = input().strip().split()
    a[int(instr[0])] = instr[1:]#put values into dict, id to set
    s1.add(int(instr[0]))

m = int(input())
b = {1:0}
del b[1]
s2 = set()
header2 = input().strip().split()
for i in range(m-1):
    instr = input().strip().split()
    b[int(instr[0])] = instr[1:]
    s2.add(int(instr[0]))

header2.pop(0)#delete id
new_header = header1 + header2

for i in range(len(new_header)):
    print(new_header[i], end=" ")
print("")

for i in sorted(s1):
    print(i, end = " ")
    print(" ".join(a[i]), end = " ")
    if(i in s2):
        print(" ".join(b[i]))
    else:
        for j in range(len(header2)):
            print("NULL", end = " ")
        print("")


================


#a, b = map(int, input().strip().split(' '))
#print(a + b)

N = int(input().strip())
buildings = [0]*N
for i in range(N):
    buildings[i] = int(input().strip())

max = 0
for i in range(N):
    for j in range(i+1,N):
        if(buildings[j] > buildings[i]):
            dist = j - i
            if dist > max:
                max = dist
            break

for i in range(N-1, -1, -1):
    for j in range(i-1, -1, -1):
        if(buildings[j] > buildings[i]):
            dist = i - j
            if dist > max:
                max = dist
            break

print(max)


==================
