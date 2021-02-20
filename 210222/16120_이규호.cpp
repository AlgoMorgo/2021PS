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

string str;
int p = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(str);
	int i = 0;
	while (i < str.length())
	{
		if (str[i] == 'P')
		{
			p++;
			i++;
		}
		else
		{
			if (p >= 2 && i != str.length() - 1 && str[i + 1] == 'P')
			{
				p--;
				i += 2;
			}
			else
			{
				p = -1;
				break;
			}
		}
	}
	p == 1 ? COUT("PPAP") : COUT("NP");

	return 0;
}