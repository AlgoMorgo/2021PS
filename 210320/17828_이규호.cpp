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

int N, X;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(N, X);
	if (26 * N < X || N > X)
	{
		COUT("!");
		return 0;
	}
	while (N)
	{
		if (N * 26 == X)
		{
			COUT('Z');
			X -= 26;
		}
		else if ((N - 1) * 26 > X)
		{
			COUT('A');
			X--;
		}
		else
		{
			int tmp = X - (N - 1) * 26;
			COUT((char)('A' + tmp - 1));
			X -= tmp;
		}

		N--;
	}

	return 0;
}