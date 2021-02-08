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
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };

int R, C, N, height;
char arr[101][101];
bool visited[101][101];
bool isLeft = false, flag;
vector<pair<int, int>> v;

void DFS(int y, int x)
{
	visited[y][x] = true;
	v.push_back({ y, x });
	if (y == 1) flag = true;
	FUP(i, 0, 3)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 1 || nx < 1 || ny > R || nx > C || arr[ny][nx] == '.' || visited[ny][nx]) continue;
		DFS(ny, nx);
	}
}

void find_height(int y, int x)
{
	int tmp = y - 1;
	FDOWN(i, y - 1, 1)
	{
		if (visited[i][x])
		{
			tmp = 1000;
			break;
		}
		if (arr[i][x] == 'x')
		{
			tmp = y - i - 1;
			break;
		}
	}
	height = min(height, tmp);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(R, C);
	FDOWN(i, R, 1)
	{
		FUP(j, 1, C)
		{
			CIN(arr[i][j]);
		}
	}
	CIN(N);
	while (N--)
	{
		int x = -1, y;
		isLeft = !isLeft;
		CIN(y);
		if (isLeft)
		{
			FUP(i, 1, C)
			{
				if (arr[y][i] == 'x')
				{
					x = i;
					break;
				}
			}
		}
		else
		{
			FDOWN(i, C, 1)
			{
				if (arr[y][i] == 'x')
				{
					x = i;
					break;
				}
			}
		}
		if (x == -1) continue;
		arr[y][x] = '.';
		FUP(i, 0, 3)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (arr[ny][nx] == 'x')
			{
				v.clear();
				MS(visited, false);
				flag = false;
				DFS(ny, nx);
				if (flag) continue;
				height = 1000;
				for (auto p : v)
				{
					find_height(p.first, p.second);
				}
				vector<pair<int, int>> tmp;
				for (auto p : v)
				{
					arr[p.first][p.second] = '.';
					tmp.push_back({ p.first - height, p.second });
				}
				for (auto p : tmp)
				{
					arr[p.first][p.second] = 'x';
				}
			}
		}
	}

	FDOWN(i, R, 1)
	{
		FUP(j, 1, C)
		{
			COUT(arr[i][j]);
		}
		ENDL;
	}

	return 0;
}