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

int arr[5][5], ans = 0, check[5][5], cnt;

void DFS(int y, int x)
{
	cnt++;
	check[y][x] = 0;
	FUP(i, 0, 3)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5 || !check[ny][nx]) continue;
		DFS(ny, nx);
	}
}

void solve(vector<int> v)
{
	FUP(i, 0, 4)
	{
		FUP(j, 0, 4)
		{
			check[i][j] = 0;
		}
	}
	int S = 0, y, x;
	for (int num : v)
	{
		y = num / 5;
		x = num % 5;
		S += arr[y][x];
		check[y][x] = 1;
	}
	if (S < 4) return;
	cnt = 0;
	DFS(y, x);
	if (cnt == 7) ans++;
}

void comb(int idx, vector<int> v)
{
	if (v.size() == 7)
	{
		solve(v);
		return;
	}
	if (idx == 25) return;
	FUP(i, idx, 24)
	{
		v.push_back(i);
		comb(i + 1, v);
		v.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	FUP(i, 0, 4)
	{
		FUP(j, 0, 4)
		{
			char tmp;
			CIN(tmp);
			arr[i][j] = tmp == 'S' ? 1 : 0;
		}
	}
	comb(0, {});
	COUT(ans);

	return 0;
}