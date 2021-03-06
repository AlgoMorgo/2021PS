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
const int INF = 1e9;

int N, dp[10000][10], arr[10000], ans[10000], l, r, Print[10000];
pair<int, int> before[10000][10]; // {전 j 인덱스, 움직임}
string A, B;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	CIN2(A, B);
	FUP(i, 0, N - 1)
	{
		arr[i] = A[i] - '0';
		ans[i] = B[i] - '0';
		FUP(j, 0, 9) dp[i][j] = INF;
	}
	int first_l = (ans[0] + 10 - arr[0]) % 10;
	int first_r = (10 - first_l) % 10;
	dp[0][first_l] = first_l;
	dp[0][0] = first_r;
	FUP(i, 1, N - 1)
	{
		l = (ans[i] + 10 - arr[i]) % 10;
		r = (10 - l) % 10;
		FUP(j, 0, 9)
		{
			if (dp[i - 1][j] == INF) continue;
			int move_l = (l + 10 - j) % 10;
			int move_r = (r +  j) % 10;
			if (dp[i][(j + move_l) % 10] > dp[i - 1][j] + move_l)
			{
				dp[i][(j + move_l) % 10] = dp[i - 1][j] + move_l;
				before[i][(j + move_l) % 10] = { j, move_l };
			}
			if (dp[i][j] > dp[i - 1][j] + move_r)
			{
				dp[i][j] = dp[i - 1][j] + move_r;
				before[i][j] = { j, -move_r };
			}
		}
	}

	int j = 0, temp = INF;
	FUP(i, 0, 9)
	{
		if (temp > dp[N - 1][i])
		{
			j = i;
			temp = dp[N - 1][i];
		}
	}
	COUT(temp);
	ENDL;
	FDOWN(i, N - 1, 1)
	{
		Print[i] = before[i][j].second;
		j = before[i][j].first;
	}
	Print[0] = j == 0 ? -first_r : first_l;
	FUP(i, 0, N - 1)
	{
		COUT2(i + 1, Print[i]);
		ENDL;
	}

	return 0;
}