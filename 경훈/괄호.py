def Calcul(num1, num2, operator): # 계산하는 함수
	if 	operator == '+':
		return num1 + num2
	elif operator == '-':
		return num1 - num2
	elif operator == '*':
		return num1 * num2

def DFS(Eq, result):
	report = result
	if len(report) == 3:
		print(Calcul(report[0],report[2],report[1]))
		return

	else:
			for j in range(len(report)):
				if j >= len(report):
					return

				if j%2 == 1:
					print(j, len(report))
					report[j-1] = Calcul(report[j-1], report[j+1], report[j])
					del report[j:j+2]
					DFS(Eq, report)

Count = int(input())
Eq = list(input())
result = list()
Max = 0


for i in range(Count):
	if (i%2) == 0:
		Eq[i] = int(Eq[i]) 
#문자형 변형하는 부분

for i in range(Count):
	if(i%2) == 1:		# 차례대로 계산
		result = Eq
		result[i-1] = Calcul(Eq[i-1], Eq[i+1], Eq[i])
		del result[i:i+2]
		DFS(Eq, result)

	# if result > Max:
	# 	Max = result
