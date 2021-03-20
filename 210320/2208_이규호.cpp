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

int N, M, ans = 0, arr[100001], dp[100001], sum[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(N, M);
	FUP(i, 1, N)
	{
		CIN(arr[i]);
		sum[i] = sum[i - 1] + arr[i];
		if (i > M) sum[i] -= arr[i - M];
	}
	dp[M] = sum[M];
	ans = max(ans, dp[M]);
	FUP(i, M + 1, N)
	{
		dp[i] = max(dp[i - 1] + arr[i], sum[i]);
		ans = max(dp[i], ans);
	}
	COUT(ans);

	return 0;
}