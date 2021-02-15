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

int N, arr[101];
ll dp[101][21];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(dp, 0);
	CIN(N);
	FUP(i, 1, N) CIN(arr[i]);
	dp[1][arr[1]] = 1;
	FUP(i, 2, N - 1)
	{
		FUP(j, 0, 20)
		{
			if (j - arr[i] >= 0)
			{
				dp[i][j - arr[i]] += dp[i - 1][j];
			}
			if (j + arr[i] <= 20)
			{
				dp[i][j + arr[i]] += dp[i - 1][j];
			}
		}
	}
	COUT(dp[N - 1][arr[N]]);

	return 0;
}