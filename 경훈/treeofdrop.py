class treemaking:
	parent_node = 0
	child_node = list()

	def __init__(self):
		self.child_node = []

N, W = input().split()
N = int(N) + 1
W = float(W)
nodelist = [0] * N

i = 0
for i in range(N):
	nodelist[i] = treemaking() 

i = 0

while i < N - 2:
	node1, node2 = input().split()
	node1 = int(node1)
	node2 = int(node2)

	if node1 < node2:
		nodelist[node2].parent_node = node1
		nodelist[node1].child_node.append(node2)
	else:
		nodelist[node1].parent_node = node2
		nodelist[node2].child_node.append(node1)

	i = i + 1

i = 0
cont = 0.0
while i < N - 1 :
	if len(nodelist[i].child_node) == 0:
		cont = cont + 1
	i = i + 1
print(W/cont)
# 	print(i, nodelist[i].parent_node, nodelist[i].child_node)
# 	i = i +1
# 	