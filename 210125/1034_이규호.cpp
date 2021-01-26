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

int N, M, K, ans = 0;
string arr[50];
bool visited[50];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(visited, false);
	CIN2(N, M);
	FUP(i, 0, N - 1) CIN(arr[i]);
	CIN(K);
	FUP(i, 0, N - 1)
	{
		if (visited[i]) continue;
		visited[i] = true;
		int cnt = 1;
		FUP(j, i + 1, N - 1)
		{
			if (arr[i] == arr[j])
			{
				cnt++;
				visited[j] = true;
			}
		}
		int off_cnt = count(arr[i].begin(), arr[i].end(), '0');
		if (off_cnt <= K && off_cnt % 2 == K % 2) ans = max(ans, cnt);
	}
	COUT(ans);

	return 0;
}