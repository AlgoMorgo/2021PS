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

int N, money;
int arr[10];
string dp[51], ans = "0";

bool comp(string a, string b)
{
	if (a.length() > b.length()) return true;
	else if (a.length() == b.length() && a > b) return true;
	else return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	FUP(i, 0, N - 1) CIN(arr[i]);
	CIN(money);
	FUP(i, 0, money) dp[i] = "";
	FUP(i, 1, money)
	{
		FUP(j, 0, N - 1)
		{
			if (i - arr[j] < 0) continue;
			string tmp = dp[i - arr[j]] + (char)('0' + j);
			sort(tmp.rbegin(), tmp.rend());
			if (tmp.front() == '0') continue;
			if (comp(tmp, dp[i])) dp[i] = tmp;
		}
		if (comp(dp[i], ans)) ans = dp[i];
	}
	COUT(ans);

	return 0;
}