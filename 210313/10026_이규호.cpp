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

int N, arr[101][101], ans[2] = { 0, 0 };
map<char, int> change = { {'R', 0}, {'G', 1}, {'B', 2} };
bool visited[101][101];

void DFS(int y, int x, int color)
{
	visited[y][x] = true;
	FUP(i, 0, 3)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 1 || nx < 1 || ny > N || nx > N || visited[ny][nx]) continue;
		if (color && arr[y][x] / 2 != arr[ny][nx] / 2) continue;
		else if (!color && arr[y][x] != arr[ny][nx]) continue;
		DFS(ny, nx, color);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	FUP(i, 1, N)
	{
		FUP(j, 1, N)
		{
			char ch;
			CIN(ch);
			arr[i][j] = change[ch];
		}
	}

	FUP(color, 0, 1)
	{
		MS(visited, false);
		FUP(i, 1, N)
		{
			FUP(j, 1, N)
			{
				if (!visited[i][j])
				{
					ans[color]++;
					DFS(i, j, color);
				}
			}
		}
	}
	COUT2(ans[0], ans[1]);
	

	return 0;
}