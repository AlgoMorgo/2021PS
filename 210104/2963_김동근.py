str = input()

sum = 1 // ��ü ��
cnt = 1 // ��� ����
weight = 5 // sum + 2*sum + 2*sum + 1 3�� ����� ���� ���� �� ���

for i in str :
	if (i == 'L') :
		sum *= 2
	elif(i == 'R') :
		sum = sum * 2 + cnt
	elif(i == '*') :
		sum = weight * sum + cnt
		cnt *= 3
print(sum)