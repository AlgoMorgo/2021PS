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

int N, M, D, E;
ll h[100001], ans = LLONG_MIN, from_1[100001], from_N[100001];
vector<pair<int, ll>> edge[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(N, M);
	CIN2(D, E);
	FUP(i, 1, N)
	{
		CIN(h[i]);
		from_1[i] = from_N[i] = LLONG_MAX;
	}
	while (M--)
	{
		int u, v, w;
		CIN3(u, v, w);
		edge[u].push_back({ v, w });
		edge[v].push_back({ u, w });
	}
	from_1[1] = from_N[N] = 0;
	priority_queue<pair<ll, int>> pq;
	pq.push({ 0, 1 });
	while (!pq.empty())
	{
		int node = pq.top().second;
		ll dist = -pq.top().first;
		pq.pop();
		if (from_1[node] < dist) continue;
		for (auto p : edge[node])
		{
			ll nd = dist + p.second;
			int next = p.first;
			if (h[next] <= h[node] || from_1[next] <= nd) continue;
			from_1[next] = nd;
			pq.push({ -nd, next });
		}
	}

	pq.push({ 0, N });
	while (!pq.empty())
	{
		int node = pq.top().second;
		ll dist = -pq.top().first;
		pq.pop();
		if (from_N[node] < dist) continue;
		for (auto p : edge[node])
		{
			ll nd = dist + p.second;
			int next = p.first;
			if (h[next] <= h[node] || from_N[next] <= nd) continue;
			from_N[next] = nd;
			pq.push({ -nd, next });
		}
	}

	FUP(i, 2, N - 1)
	{
		if (from_1[i] == LLONG_MAX || from_N[i] == LLONG_MAX) continue;
		ans = max(ans, h[i] * E - (from_1[i] + from_N[i]) * D);
	}
	ans == LLONG_MIN ? COUT("Impossible") : COUT(ans);

	return 0;
}