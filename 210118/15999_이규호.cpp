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
const int MOD = 1e9 + 7;

int N, M, cnt = 0;
ll ans = 1;
char arr[2000][2000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(N, M);
	FUP(i, 0, N - 1)
	{
		FUP(j, 0, M - 1)
		{
			CIN(arr[i][j]);
		}
	}

	FUP(i, 0, N - 1)
	{
		FUP(j, 0, M - 1)
		{
			int ok = 1;
			FUP(k, 0, 3)
			{
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
				if (arr[ny][nx] != arr[i][j])
				{
					ok = 0;
					break;
				}
			}
			cnt += ok;
		}
	}

	FUP(i, 1, cnt)
	{
		ans *= 2;
		ans %= MOD;
	}
	COUT(ans);

	return 0;
}