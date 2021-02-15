#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define CIN(a) cin >> a;
#define CIN2(a, b) cin >> a >> b
#define CIN3(a, b, c) cin >> a >> b >> c
#define COUT(a) cout << a
#define COUT2(a, b) cout << a << ' ' << b
#define COUT3(a, b, c) cout << a << ' ' << b << ' ' << c
#define ENDL cout << '\n'
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N, a, b, ans = 0, parent[200001];

int find(int x)
{
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void update(int x, int y)
{
	if (x > y) swap(x, y);
	x = find(x);
	y = find(y);
	parent[y] = x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	priority_queue<pair<int, int>> pq;
	CIN(N);
	FUP(i, 1, N)
	{
		parent[i] = i;
		CIN2(a, b);
		if (a >= N) ans += b;
		else pq.push({ b, a });
	}
	while (!pq.empty())
	{
		int cup = pq.top().first;
		int deadline = pq.top().second;
		pq.pop();
		int idx = find(deadline);
		if (idx == 0) continue;
		ans += cup;
		update(idx, idx - 1);
	}
	COUT(ans);

	return 0;
}