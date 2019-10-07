import copy
import math

Cmp = 0
global Max
Max = 0

def Compass(i,j,a,b,D):
	A = math.sqrt((i - a) ** 2 + (j - b) ** 2)
	if D >= A:
		return A
	else:
		return 0

def slay_the_enemy(MapB, D):
	Last = len(MapB) - 1
	global Cmp
	global Max
	Loca_B = list()				#궁수위치 탐색
	Loca_E = list()				#적위치 탐색
	CheckList = [[D, 17,17],[D, 17,17],[D, 17,17]]	# 적이 없을 경우 대비
	for i in range(len(MapB[0])):
		if MapB[Last][i] == 2:
			Loca_B.append(i)

	for k in range(Last):						# 턴 회수 제한
		for i in range(k, Last):
			for j in range(len(MapB[0])):
				if MapB[i][j] == 1:
					Loca_E.append([i,j])

		
		for i in range(3):						# 적과의 거리 계산 
			for j in range(len(Loca_E)):
				C = Compass(Last, Loca_B[i], Loca_E[j][0], Loca_E[j][1], D)
				if C :
					if CheckList[i][0] > C:		# 가장 짧은데 + 왼쪽 조건
						CheckList[i][0] = C
						CheckList[i][1] = Loca_E[j][0]
						CheckList[i][2] = Loca_E[j][1]

					elif CheckList[i][0] == C and CheckList[i][2] > Loca_E[j][1]:
						CheckList[i][0] = C
						CheckList[i][1] = Loca_E[j][0]
						CheckList[i][2] = Loca_E[j][1]

		for i in range(3):								# 최종적으로 쏘는 경우의수 계산 
			if CheckList[i][1] < 17:
				if MapB[CheckList[i][1]][CheckList[i][2]]:
					MapB[CheckList[i][1]][CheckList[i][2]] = 0
					Cmp = Cmp + 1

		for i in range(Last - k):						# 한턴 넘기기 
			MapB[Last-i] = copy.deepcopy(MapB[Last - i - 1])

		Loca_E = list()
		CheckList = [[D, 17,17],[D, 17,17],[D, 17,17]]

	
	if Max < Cmp:
		Max = Cmp
	Cmp = 0

def DFS(MapA, i, D):
	MapB = copy.deepcopy(MapA)
	if sum(MapB[len(MapB)-1]) != 6:
		for j in range(i + 1,len(MapB[0])):
			MapB[len(MapB) - 1][j] = 2
			DFS(MapB, j, D)
			MapB[len(MapB) - 1][j] = 0
	else:
		slay_the_enemy(MapB, D)	# 궁수 자리 다 채우고 적 죽이기 시작

cond = input().split()
cond = [int (i) for i in cond ] # 매번 이렇게 변환해야하나??
MapA = list()
Temp = list()
C = 0

for i in range(cond[0]):		# 입력받기
	MapA.append(input().split())
	MapA[i] = [int (j) for j in MapA[i]]
	
for i in range(cond[1]):		# 궁수(2)가 존재할 줄 추가
	Temp.append(0)

MapA.append(Temp)

for i in range(cond[1] - 2):
	MapA[cond[0]][i] = 2
	DFS(MapA, i, cond[2])
	MapA[cond[0]][i] = 0

print(Max)