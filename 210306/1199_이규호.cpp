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

int N, arr[1001][1001];

void DFS(int node)
{
	FUP(i, 1, N)
	{
		if (arr[node][i])
		{
			arr[node][i]--;
			arr[i][node]--;
			DFS(i);
		}
	}
	COUT2(node, "");
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	bool ok = true;
	CIN(N);
	FUP(i, 1, N)
	{
		int cnt = 0;
		FUP(j, 1, N)
		{
			CIN(arr[i][j]);
			cnt += arr[i][j];
		}
		if (cnt % 2) ok = false;
	}
	if (!ok) COUT(-1);
	else DFS(1);

	return 0;
}