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

int N, arr[501][501], dp[501][501], K = 1;

void DFS(int y, int x)
{
	dp[y][x] = 1;
	FUP(i, 0, 3)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
		if (arr[ny][nx] <= arr[y][x]) continue;
		if (dp[ny][nx] == 0) DFS(ny, nx);
		dp[y][x] = max(dp[y][x], dp[ny][nx] + 1);
	}
	K = max(K, dp[y][x]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(dp, 0);
	CIN(N);
	FUP(i, 1, N)
	{
		FUP(j, 1, N)
		{
			CIN(arr[i][j]);
		}
	}

	FUP(i, 1, N)
	{
		FUP(j, 1, N)
		{
			if (dp[i][j] == 0)
			{
				DFS(i, j);
			}
		}
	}
	COUT(K);

	return 0;
}