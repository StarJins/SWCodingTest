N = input()
N = int(N)

Numlist = input()
Numlist = Numlist.split()

cont = 0

for i in range(N):
	checklist = [] + Numlist
	del checklist[i]

	if checklist == sorted(checklist):
		cont = cont + 1
	
print(cont)