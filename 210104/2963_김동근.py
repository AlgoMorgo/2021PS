str = input()

sum = 1 // 전체 합
cnt = 1 // 노드 개수
weight = 5 // sum + 2*sum + 2*sum + 1 3개 노드의 합을 구할 때 사용

for i in str :
	if (i == 'L') :
		sum *= 2
	elif(i == 'R') :
		sum = sum * 2 + cnt
	elif(i == '*') :
		sum = weight * sum + cnt
		cnt *= 3
print(sum)