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

int answer = 30, paper[5] = { 5, 5, 5, 5, 5 };
vector<vector<int>> arr(10);

int use_paper()
{
	int ret = 25;
	FUP(i, 0, 4) ret -= paper[i];
	return ret;
}

void change(int y, int x, int len)
{
	FUP(i, y, y + len)
	{
		FUP(j, x, x + len)
		{
			arr[i][j] ^= 1;
		}
	}
}

void solve(int y, int x, int remain)
{
	if (remain == 0)
	{
		answer = min(answer, use_paper());
		return;
	}
	if (x >= 10)
	{
		solve(y + 1, 0, remain);
		return;
	}
	if (!arr[y][x]) solve(y, x + 1, remain);
	FUP(len, 0, 4)
	{
		if (x + len >= 10 || y + len >= 10) break;
		bool ok = true;
		FUP(i, y, y + len)
		{
			if (!arr[i][x + len]) ok = false;
		}
		FUP(j, x, x + len)
		{
			if (!arr[y + len][j]) ok = false;
		}
		if (!ok) break;
		if (!paper[len]) continue;
		change(y, x, len);
		paper[len]--;
		solve(y, x + len + 1, remain - (len + 1) * (len + 1));
		paper[len]++;
		change(y, x, len);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int remain = 0;
	FUP(i, 0, 9)
	{
		arr[i].resize(10);
		FUP(j, 0, 9)
		{
			CIN(arr[i][j]);
			remain += arr[i][j];
		}
	}
	solve(0, 0, remain);
	answer == 30 ? COUT(-1) : COUT(answer);

	return 0;
}