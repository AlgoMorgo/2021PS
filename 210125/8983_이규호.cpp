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

int N, M, L, ans = 0;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN3(N, M, L);
	FUP(i, 0, N - 1)
	{
		int tmp;
		CIN(tmp);
		v.push_back(tmp);
	}
	sort(ALL(v));
	while (M--)
	{
		int x, y;
		CIN2(x, y);
		if (y > L) continue;
		int low = x - (L - y), upper = x + (L - y);
		auto iter = lower_bound(ALL(v), low);
		if (iter != v.end() && *iter <= upper) ans++;
	}
	COUT(ans);

	return 0;
}