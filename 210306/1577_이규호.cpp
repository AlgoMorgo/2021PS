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

ll N, M, K, arr[101][101][2], dp[101][101];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(dp, 0);
	MS(arr, 0);
	CIN3(M, N, K);
	while (K--)
	{
		int a, b, c, d;
		CIN2(b, a);
		CIN2(d, c);
		if (a > c) swap(a, c);
		if (b > d) swap(b, d);
		arr[a][b][a == c] = 1; // 가로 1, 세로 0
	}
	dp[0][0] = 1;
	FUP(i, 0, N)
	{
		FUP(j, 0, M)
		{
			if (j != M && !arr[i][j][1]) dp[i][j + 1] += dp[i][j];
			if (i != N && !arr[i][j][0]) dp[i + 1][j] += dp[i][j];
		}
	}
	COUT(dp[N][M]);

	return 0;
}