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

struct Node
{
	int v, c, d;
	Node(int vv, int cc, int dd) : v(vv), c(cc), d(dd) {}
};

struct compare
{
	bool operator()(Node A, Node B)
	{
		return A.d > B.d;
	}
};

int T, N, M, K, u, v, c, d;
int dist[101][10001]; // i까지 j원으로 도착할때 최소시간
vector<Node> edge[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(T);
	while (T--)
	{
		CIN3(N, M, K);
		FUP(i, 1, N)
		{
			edge[i].clear();
			FUP(j, 0, M)
			{
				dist[i][j] = INT_MAX;
			}
		}
		while (K--)
		{
			CIN2(u, v);
			CIN2(c, d);
			edge[u].push_back(Node(v, c, d));
		}

		priority_queue<Node, vector<Node>, compare> pq;
		dist[1][0] = 0;
		pq.push(Node(1, 0, 0));
		string answer = "Poor KCM";
		while (!pq.empty())
		{
			Node node = pq.top();
			if (node.v == N)
			{
				answer = to_string(node.d);
				break;
			}
			pq.pop();
			if (dist[node.v][node.c] < node.d) continue;
			for (Node next : edge[node.v])
			{
				if (node.c + next.c > M || dist[next.v][node.c + next.c] <= node.d + next.d) continue;
				dist[next.v][node.c + next.c] = node.d + next.d;
				pq.push(Node(next.v, node.c + next.c, node.d + next.d));
			}
		}
		COUT(answer);
		ENDL;
	}

	return 0;
}