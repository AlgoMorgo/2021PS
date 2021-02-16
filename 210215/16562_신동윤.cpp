#include <bits/stdc++.h>

#define MAX 10001

using namespace std;

int N, M, K, answer;
int money[MAX], parent[MAX];

int _find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = _find(parent[x]);
}

void _union(int x, int y) {
    x = _find(x);
    y = _find(y);

    if (x == y) return;

    if (money[x] < money[y])
        parent[y] = x;  // 친구비 더 적은 놈이 부모
    else
        parent[x] = y;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M >> K;

    for (int i = 1; i <= N; ++i) cin >> money[i];

    for (int i = 0; i <= N; ++i) parent[i] = i;

    while (M--) {
        int v, w;
        cin >> v >> w;
        _union(v, w);
    }

    for (int i = 1; i <= N; ++i)
        if (parent[i] == i)  // 다른 집합이면 친구비 내야
            answer += money[i];

    if (K < answer)
        cout << "Oh no";
    else
        cout << answer;

    return 0;
}