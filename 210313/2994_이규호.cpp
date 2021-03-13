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

int T, N, arr[500], max_time = 0;
bool isFirst[500];
pair<bool, int> dp[5001]; // 가능, 이전 담은 idx

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(T, N);
	FUP(i, 0, N - 1)
	{
		CIN(arr[i]);
		isFirst[i] = false;
	}
	FUP(i, 1, T) dp[i].first = false;
	dp[0] = { true, -1 };
	FUP(i, 0, N - 1)
	{
		FDOWN(j, max_time, 0)
		{
			if (dp[j].first && j + arr[i] <= T && !dp[j + arr[i]].first)
			{
				dp[j + arr[i]] = { true, i };
				max_time = max(max_time, j + arr[i]);
			}
		}
	}
	int idx = max_time;
	while (idx != 0)
	{
		int node = dp[idx].second;
		isFirst[node] = true;
		idx -= arr[node];
	}
	int bag[2] = { 0, 0 };
	FUP(i, 0, N - 1)
	{
		COUT2(bag[isFirst[i]], "");
		bag[isFirst[i]] += arr[i];
	}

	return 0;
}