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

int N, K, S, ans = 0;
pair<int, int> apart[30000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN3(N, K, S);
	FUP(i, 0, N - 1) CIN2(apart[i].first, apart[i].second);
	sort(apart, apart + N);
	int mid = N - 1;
	FUP(i, 0, N - 1)
	{
		if (S < apart[i].first)
		{
			mid = i - 1;
			break;
		}
	}
	if (mid != -1) // ¿ÞÂÊ
	{
		int idx = 0;
		while (idx <= mid)
		{
			int first = apart[idx].first;
			int remain = K;
			while (idx <= mid)
			{
				if (apart[idx].second > remain)
				{
					apart[idx].second -= remain;
					break;
				}
				remain -= apart[idx++].second;
			}
			ans += (2 * (S - first));
		}
	}
	if (mid != N - 1) // ¿À¸¥ÂÊ
	{
		int idx = N - 1;
		while (idx > mid)
		{
			int first = apart[idx].first;
			int remain = K;
			while (idx > mid)
			{
				if (apart[idx].second > remain)
				{
					apart[idx].second -= remain;
					break;
				}
				remain -= apart[idx--].second;
			}
			ans += (2 * (first - S));
		}
	}
	COUT(ans);

	return 0;
}