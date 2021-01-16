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
#define MAX 100001
#define POW 17 //N�� �ִ� ����

int a, b, c, N, M, depth[MAX];
pair<int, int> par[MAX][POW + 1];
vector<pair<int, int>> edge[MAX];

void input()
{
	CIN(N);
	FUP(i, 1, N - 1)
	{
		CIN3(a, b, c);
		edge[a].push_back({ b, c });
		edge[b].push_back({ a, c });
	}
}

void DFS(int node, int before, int dist)
{
	par[node][0].first = before;
	par[node][0].second = dist;
	depth[node] = depth[before] + 1;
	for (auto next : edge[node])
	{
		if (next.first == before) continue;
		DFS(next.first, node, next.second);
	}
}

void setPar()
{
	FUP(j, 1, POW)
	{
		FUP(i, 1, N)
		{
			par[i][j].first = par[par[i][j - 1].first][j - 1].first;
			par[i][j].second = par[par[i][j - 1].first][j - 1].second + par[i][j - 1].second;
		}
	}
}

int LCA(int x, int y)
{
	int cnt = 0;
	if (depth[x] > depth[y]) swap(x, y);
	//x, y ���� ���߱�
	FDOWN(i, POW, 0)
	{
		if (depth[y] - depth[x] >= (1 << i))
		{
			cnt += par[y][i].second;
			y = par[y][i].first;
		}
	}
	//��ġ�� ��� ��ȯ
	if (x == y) return cnt;
	//�ּ� ���� ������ �ٷ� �Ʒ� ����
	FDOWN(i, POW, 0)
	{
		if (par[x][i].first != par[y][i].first)
		{
			cnt += par[x][i].second + par[y][i].second;
			x = par[x][i].first;
			y = par[y][i].first;
		}
	}
	//�θ� ��ȯ
	return cnt + par[x][0].second + par[y][0].second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	depth[0] = 0;
	DFS(1, 0, 0);
	setPar();

	CIN(M);
	while (M--)
	{
		CIN2(a, b);
		COUT(LCA(a, b));
		ENDL;
	}

	return 0;
}