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
#define piii pair<pair<int, int>, int>


int N, C, M, a, b, c, box[2001], ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(box, 0);
	CIN3(N, C, M);
	priority_queue<piii, vector<piii>, greater<piii>> pq;
	while (M--)
	{
		CIN3(a, b, c);
		pq.push({ {b, a}, c });
	}
	while (!pq.empty())
	{
		int start = pq.top().first.second;
		int end = pq.top().first.first - 1;
		int num = pq.top().second;
		pq.pop();
		int cnt = 0;
		FUP(i, start, end)
		{
			cnt = max(cnt, box[i]);
		}
		FUP(i, start, end)
		{
			num = min(num, C - cnt);
		}
		ans += num;
		FUP(i, start, end)
		{
			box[i] += num;
		}
	}
	COUT(ans);

	return 0;
}