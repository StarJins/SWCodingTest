def intensity(value):
	if value < 510000 and value >= 0:
		return '#'

	elif value < 1020000 and value >= 510000:
		return 'o'

	elif value < 1530000 and value >= 1020000:
		return '+'

	elif value < 2040000 and value >= 1530000:
		return '-'

	elif value >= 2040000:
		return '.'

N, M = input().split()	#스페이스로 구분하여 입력받기
list = [0]			#빈 리스트 생성
i = 0
while i < int(N) :		#파이썬은 for문과  while 문 사용이 약간 다름
	i = i + 1
	list = list + input().split()		# 파이썬은 list도 + 쓸 수 있음!

# 여기가지가 입력부
i = 1
while i <  3 * int(N) * int(M):
	if (i-1) % (33) == 0 and (i-1) != 0:
		print('\n')
	print(intensity(int(list[i])*2126 + int(list[i+1])*7152 + int(list[i+2]) *722), end = '')
	i = i + 3
