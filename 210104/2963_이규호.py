import math

s = input()
X = 1  # 노드들의 합
cnt = 1 # 노드 갯수
for ch in s:
    if ch == 'L':
        X *= 2.
    if ch == 'R':
        X = X * 2 + cnt
    elif ch == '*': # *이면 P, L, R을 다 더해줘야 됨. 노드의 수도 3배가 됨.
        X = X * 5 + cnt
        cnt *= 3
print(X)
