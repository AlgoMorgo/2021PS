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

int N, dp[50001];
pair<int, int> coin[100];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	FUP(T, 1, 3)
	{
		int sum = 0, max_money = 0;
		MS(dp, 0);
		dp[0] = 1;
		CIN(N);
		FUP(i, 0, N - 1)
		{
			CIN2(coin[i].first, coin[i].second);
			sum += (coin[i].first * coin[i].second);
		}
		if (sum % 2)
		{
			COUT("0\n");
			continue;
		}
		sum /= 2;
		FUP(i, 0, N - 1)
		{
			FDOWN(j, max_money, 0)
			{
				if (dp[j])
				{
					FUP(k, 1, coin[i].second)
					{
						int l = j + coin[i].first * k;
						if (l > sum) break;
						dp[l] = 1;
						max_money = max(max_money, l);
					}
				}
			}
		}
		COUT(dp[sum]);
		ENDL;
	}


	return 0;
}