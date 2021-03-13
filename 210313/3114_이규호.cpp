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

struct Node
{
	char what;
	int cnt, ax, by;
	Node() { ax = by = 0; }
};

int R, C, dp[1501][1501];
Node arr[1501][1501];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	CIN2(R, C);
	FUP(i, 1, R)
	{
		FUP(j, 1, C)
		{
			CIN2(arr[i][j].what, arr[i][j].cnt);
			arr[i][j].ax = arr[i][j - 1].ax;
			arr[i][j].by = arr[i - 1][j].by;
			if (arr[i][j].what == 'A') arr[i][j].ax += arr[i][j].cnt;
			else arr[i][j].by += arr[i][j].cnt;
		}
	}
	FDOWN(i, R, 1)
	{
		FDOWN(j, C, 1)
		{
			dp[i - 1][j] = max(dp[i - 1][j], dp[i][j] + arr[i][j - 1].ax);
			dp[i][j - 1] = max(dp[i][j - 1], dp[i][j] + arr[i - 1][j].by);
			dp[i - 1][j - 1] = max(dp[i - 1][j - 1], dp[i][j] + arr[i][j - 1].ax + arr[i - 1][j].by);
		}
	}
	COUT(dp[1][1]);



	return 0;
}