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

ll T, N, X[501];
long double a, b, c, d;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(T);
	while (T--)
	{
		CIN(N);
		FUP(i, 1, N) CIN(X[i]);
		if (N <= 4)
		{
			COUT("YES\n");
			continue;
		}
		d = -X[4] + 4 * X[3] - 6 * X[2] + 4 * X[1];
		c = (2 * X[3] - 9 * X[2] + 18 * X[1] - 11 * d) / 6;
		b = -(X[2] - 8 * X[1] + 6 * c + 7 * d) / 4;
		a = X[1] - b - c - d;
		//cout << a << ' '  << b << ' ' << c << ' ' << d << '\n';
		string ans = "YES\n";
		FUP(i, 5, N)
		{
			if ((int)(a * pow(i, 3) + b * pow(i, 2) + c * i + d + 0.000001) != X[i])
			{
				ans = "NO\n";
				break;
			}
		}
		COUT(ans);
	}

	return 0;
}