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

int N, M, arr[101], dp[101][51][2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(dp, 0);
	CIN2(N, M);
	FUP(j, 0, M) dp[0][j][0] = dp[0][j][1] = -1e6;
	dp[0][0][0] = 0;
	FUP(i, 1, N)
	{
		CIN(arr[i]);
		dp[i][0][0] = dp[i][0][1] = 0;
		FUP(j, 1, M) dp[i][j][0] = dp[i][j][1] = -1e6;
	}
	dp[1][1][1] = arr[1];
	FUP(i, 2, N)
	{
		FUP(j, 1, M)
		{
			dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1]);
			dp[i][j][1] = max({ dp[i - 2][j - 1][0], dp[i - 2][j - 1][1], dp[i - 1][j][1] }) + arr[i];
		}
	}

	COUT(max(dp[N][M][0], dp[N][M][1]));

	return 0;
}