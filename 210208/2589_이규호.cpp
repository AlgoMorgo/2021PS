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

int N, M, ans = 0;
char arr[50][50];
bool visited[50][50];


void BFS(int i, int j)
{
	queue<pair<pair<int, int>, int>> q;
	MS(visited, false);
	q.push({ { i, j }, 0 });
	visited[i][j] = true;
	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int dist = q.front().second;
		q.pop();
		ans = max(ans, dist);
		FUP(d, 0, 3)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx] || arr[ny][nx] == 'W') continue;
			visited[ny][nx] = true;
			q.push({ {ny, nx}, dist + 1 });
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(N, M);
	FUP(i, 0, N - 1)
	{
		FUP(j, 0, M - 1)
		{
			CIN(arr[i][j]);
		}
	}
	FUP(i, 0, N - 1)
	{
		FUP(j, 0, M - 1)
		{
			if (arr[i][j] == 'L')
			{
				BFS(i, j);
			}
		}
	}
	COUT(ans);

	return 0;
}