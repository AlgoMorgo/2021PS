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

int T, N, dp[10030];
pair<int, int> arr[10030];

int train7(int idx)
{
	int tmp[8];
	int first = idx - 7;
	tmp[0] = 0;
	FUP(i, first + 1, first + 7)
	{
		tmp[i - first] = tmp[i - first - 1] + min(arr[i].second, 6);
	}
	return tmp[7];
}

int train30(int idx)
{
	int tmp[31];
	int first = idx - 30;
	tmp[0] = 0;
	FUP(i, first + 1, first + 30)
	{
		tmp[i - first] = tmp[i - first - 1] + min(arr[i].second, 6);
		if (i - first >= 7)
		{
			tmp[i - first] = min(tmp[i - first], tmp[i - first - 7] + 36);
		}
	}
	return tmp[30];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(T);
	MS(arr, 0);
	while (T--)
	{
		MS(dp, 0);
		CIN(N);
		FUP(i, 30, 29 + N)
		{
			CIN2(arr[i].first, arr[i].second);
			arr[i].second *= 2;
			int bus = arr[i].first, train = arr[i].second;
			dp[i] = min({ 
				dp[i - 1] + bus + train,
				dp[i - 1] + 3 + train,
				dp[i - 1] + 6,
				dp[i - 7] + 18 + train7(i),
				dp[i - 7] + 36,
				dp[i - 30] + 45 + train30(i),
				dp[i - 30] + 90 });
		}
		COUT(dp[N + 29]);
		ENDL;
	}


	return 0;
}