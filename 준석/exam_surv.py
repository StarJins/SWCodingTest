
N = int(input().strip())
students = []
instr = input().strip().split()
for i in range(N):
    students.append(int(instr[i]))
B, C = map(int, input().strip().split())

sum = 0
for i in range(N):
    temp = students[i] - B
    sum = sum + 1
    if temp <= 0:
        continue
    elif temp%C == 0:
        sum = sum + int(temp/C)
    else:
        sum = sum + int(temp/C) + 1

print(sum)