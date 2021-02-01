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

const int INF = 987654321;
int N, M, S, D, arr[500], u, v, w;
vector<int> before[500];
map<int, int> dist[500];

void DFS(int node)
{
	auto iter = before[node].begin();
	while(!before[node].empty())
	{
		dist[*iter][node] = -1;
		DFS(*iter);
		iter = before[node].erase(iter);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true)
	{
		CIN2(N, M);
		if (!N) break;
		CIN2(S, D);
		FUP(i, 0, N - 1)
		{
			dist[i].clear();
			arr[i] = INF;
			before[i].clear();
		}
		while (M--)
		{
			CIN3(u, v, w);
			dist[u][v] = w;
		}
		priority_queue<pair<int, int>> pq; // {거리, 노드}
		arr[S] = 0;
		pq.push({ 0, S });
		while (!pq.empty())
		{
			int node = pq.top().second;
			int d = -pq.top().first;
			pq.pop();
			if (node == D) break;
			for(auto p : dist[node])
			{
				int nd = p.second + d;
				if (nd > arr[p.first]) continue;
				else if (nd == arr[p.first]) before[p.first].push_back(node);
				else
				{
					before[p.first].clear();
					before[p.first].push_back(node);
					arr[p.first] = nd;
					pq.push({ -nd, p.first });
				}
			}
		}
		while (!pq.empty()) { pq.pop(); }
		DFS(D);

		FUP(i, 0, N - 1) arr[i] = INF;
		arr[S] = 0;
		pq.push({ 0, S });
		while (!pq.empty())
		{
			int node = pq.top().second;
			int d = -pq.top().first;
			pq.pop();
			if (node == D) break;
			for (auto p : dist[node])
			{
				if (p.second == -1 || p.second + d >= arr[p.first]) continue;
				arr[p.first] = d + p.second;
				pq.push({ -arr[p.first], p.first });
			}
		}
		arr[D] == INF ? COUT(-1) : COUT(arr[D]);
		ENDL;
	}

	return 0;
}