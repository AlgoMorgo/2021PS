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

int L, K, C, answer, tmp, first, arr[10002];

bool solve(int len)
{
	int cnt = 0, sum = 0;
	tmp = -1;
	FDOWN(i, K - 1, 0)
	{
		if (sum + arr[i + 1] - arr[i] > len)
		{
			cnt++;
			sum = arr[i + 1] - arr[i];
			if (sum > len) return false;
			tmp = i + 1;
		}
		else
		{
			sum += arr[i + 1] - arr[i];
		}
	}
	if (cnt < C) tmp = 1;
	return cnt <= C;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN3(L, K, C);
	arr[0] = 0, arr[K + 1] = L;
	FUP(i, 1, K) CIN(arr[i]);
	K++;
	sort(arr, arr + K);
	int l = 1, r = L;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (solve(mid))
		{
			answer = mid;
			first = tmp;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	COUT2(answer, arr[first]);


	return 0;
}