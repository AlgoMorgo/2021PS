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

int N, L, P, ans = 0;
pair<int, int> arr[10000];
 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	FUP(i, 0, N - 1) CIN2(arr[i].first, arr[i].second);
	CIN2(L, P);
	sort(arr, arr + N);
	int idx = 0;
	priority_queue<int> pq;
	while (P < L)
	{
		while (idx < N && arr[idx].first <= P)
		{
			pq.push(arr[idx++].second);
		}
		if (pq.empty())
		{
			ans = -1;
			break;
		}
		P += pq.top();
		pq.pop();
		ans++;
	}
	COUT(ans);

	return 0;
}