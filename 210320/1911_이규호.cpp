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

int N, L, ans = 0, idx = 0, check = 0;
pair<int, int> arr[10000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(N, L);
	FUP(i, 0, N - 1) CIN2(arr[i].first, arr[i].second);
	sort(arr, arr + N);
	while (idx < N)
	{
		if (check < arr[idx].first) check = arr[idx].first;
		while (check < arr[idx].second)
		{
			check += L;
			ans++;
		}
		idx++;
	}
	COUT(ans);

	return 0;
}