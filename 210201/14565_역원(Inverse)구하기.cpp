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

ll N, A;

ll exEuclid(ll a, ll b, ll & x, ll & y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	ll gcd = exEuclid(b, a % b, x, y);
	ll temp = y;
	y = x - (a / b) * y;
	x = temp;
	if (x <= 0)
	{
		x += b;
		y -= a;
	}
	return gcd;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(N, A);
	COUT2(N - A, "");
	ll x, y;
	exEuclid(A, N, x, y) == 1 ? COUT(x) : COUT(-1);

	return 0;
}