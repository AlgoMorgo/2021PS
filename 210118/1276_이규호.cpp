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

int N, ans = 0, height[10000];
pair<int, pair<int, int>> arr[100];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(height, 0);
	CIN(N);
	FUP(i, 0, N - 1)
	{
		CIN3(arr[i].first, arr[i].second.first, arr[i].second.second);
	}
	sort(arr, arr + N);
	FUP(i, 0, N - 1)
	{
		int y = arr[i].first;
		int left = arr[i].second.first;
		int right = arr[i].second.second;
		ans += (y - height[left]);
		ans += (y - height[right - 1]);
		FUP(h, left, right - 1) height[h] = y;
	}
	COUT(ans);

	return 0;
}