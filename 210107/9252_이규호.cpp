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

int N, M;
string x, y;
int dp[1001][1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(x, y);
	N = x.size(), M = y.size();
	FUP(i, 1, N)
	{
		FUP(j, 1, M)
		{
			/*
				x의 i -1 번째, y의 j - 1번째 까지 확인해서 가능한 LCS
				3가지 경우를 확인하면 됨.
			*/
			dp[i][j] = max({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + (x[i - 1] == y[j - 1]) });
		}
	}
	int i = N, j = M;
	stack<char> answer;
	while (i >= 1 && j >= 1)
	{
		if (dp[i][j] == dp[i - 1][j]) i--;
		else if (dp[i][j] == dp[i][j - 1]) j--;
		else
		{
			// [i - 1][j - 1] == [i][j]인 경우가 LCS에 글자를 추가한 경우임.
			answer.push(x[i - 1]);
			i--, j--;
		}
	}
	COUT(dp[N][M]);
	ENDL;
	while (!answer.empty())
	{
		COUT(answer.top());
		answer.pop();
	}


	return 0;
}