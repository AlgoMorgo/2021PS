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


int N, M, dp[10001];
pair<int, int> arr[100];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(dp, 0);
	CIN2(N, M);
	FUP(i, 0, N - 1) CIN(arr[i].first);
	FUP(i, 0, N - 1) CIN(arr[i].second);
	sort(arr, arr + N);
	FUP(i, 0, N - 1)
	{
		FDOWN(j, 10000, arr[i].second)
		{
			dp[j] = max(dp[j], dp[j - arr[i].second] + arr[i].first);
		}
	}
	FUP(i, 0, 10000)
	{
		if (dp[i] >= M)
		{
			COUT(i);
			break;
		}
	}


	return 0;
}