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

int N, S, dp[300001];
pair<int, int> arr[300001];
vector<int> height, price;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	arr[0] = { 0, 0 };
	MS(dp, 0);
	CIN2(N, S);
	FUP(i, 1, N) CIN2(arr[i].first, arr[i].second);
	sort(arr, arr + N + 1);
	FUP(i, 0, N)
	{
		height.push_back(arr[i].first);
		price.push_back(arr[i].second);
	}
	FUP(i, 1, N)
	{
		if (height[i] < S) continue;
		int idx = upper_bound(ALL(height), height[i] - S) - height.begin() - 1;
		dp[i] = max(dp[i - 1], dp[idx] + price[i]);
	}
	COUT(dp[N]);

	return 0;
}