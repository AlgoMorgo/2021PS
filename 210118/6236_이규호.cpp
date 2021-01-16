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

int N, M, arr[100000], ans = -1;

int solve(int num)
{
	int cnt = 0, money = 0;
	FUP(i, 0, N - 1)
	{
		if (money < arr[i])
		{
			cnt++;
			money = num - arr[i];
		}
		else money -= arr[i];
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(N, M);
	int left = 0, right = 1000000000;
	FUP(i, 0, N - 1)
	{
		CIN(arr[i]);
		left = max(left, arr[i]);
	}
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int cnt = solve(mid);
		if (cnt > M) left = mid + 1;
		else
		{
			ans = mid;
			right = mid - 1;
		}
	}
	COUT(ans);


	return 0;
}