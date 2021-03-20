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

int N, M, fox[4001], wolf[4001][2], a, b, d, ans = 0;
vector<pair<int, int>> edge[4001];

void fBFS()
{
	fox[1] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, 1 });
	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (dist > fox[node]) continue;
		for (auto p : edge[node])
		{
			int next = p.first;
			int nd = p.second;
			if (fox[next] > dist + nd)
			{
				fox[next] = dist + nd;
				pq.push({ -fox[next], next });
			}
		}
	}
}

void wBFS()
{
	wolf[1][1] = 0;
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ 0, {1, 1} });
	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int node = pq.top().second.first;
		int idx = pq.top().second.second;
		pq.pop();
		if (dist > wolf[node][idx]) continue;
		int ni = idx ^ 1;
		{
			for (auto p : edge[node])
			{
				int next = p.first;
				int nd = idx ? p.second / 2 : p.second * 2;
				if (wolf[next][ni] > dist + nd)
				{
					wolf[next][ni] = dist + nd;
					pq.push({ -wolf[next][ni], {next, ni} });
				}
			}
		}

	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(N, M);
	FUP(i, 1, N) fox[i] = wolf[i][0] = wolf[i][1] = INT_MAX;
	while (M--)
	{
		CIN3(a, b, d);
		edge[a].push_back({ b, 2 * d });
		edge[b].push_back({ a, 2 * d });
	}
	fBFS();
	wBFS();
	FUP(i, 2, N)
	{
		if (fox[i] < min(wolf[i][1], wolf[i][0])) ans++;
	}
	COUT(ans);

	return 0;
}