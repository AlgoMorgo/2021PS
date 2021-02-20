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

int R, C, ans = 0;
char arr[1500][1500]; // �� ����
bool visited[1500][1500], check[1500][1500]; // visited :  ������ �湮 üũ, check : ���� �ߺ����� �ȳְ� üũ
vector<pair<int, int>> L; // L : ����(size�� 2)
vector<pair<int, int>> ice, next_ice; // ice : �̹��� ���� ��, next : ������ ���� ��
queue<pair<int, int>> q; // ���� BFS ���� queue


// ������ ����ų� �����̸� false return
bool can(pair<int, int> a)
{
	int y = a.first, x = a.second;
	if (y < 0 || x < 0 || y >= R || x >= C || arr[y][x] == 'X') return false;
	return true;
}

bool BFS()
{
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		FUP(i, 0, 3)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!can({ ny, nx }) || visited[ny][nx]) continue;
			visited[ny][nx] = true;
			q.push({ ny, nx });
		}
	}

	return visited[L[1].first][L[1].second];
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(R, C);
	FUP(i, 0, R - 1)
	{
		FUP(j, 0, C - 1)
		{
			visited[i][j] = false;
			CIN(arr[i][j]);
			if (arr[i][j] == 'L')
			{
				arr[i][j] = '.';
				L.push_back({ i, j });
			}
		}
	}

	// ó���� ���� ���ǵ� üũ
	FUP(i, 0, R - 1)
	{
		FUP(j, 0, C - 1)
		{
			if (arr[i][j] != 'X') continue;
			check[i][j] = false;
			FUP(k, 0, 3)
			{
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (can({ ny, nx }))
				{
					check[i][j] = true;
					ice.push_back({ i, j });
					break;
				}
			}
		}
	}
	q.push({ L[0].first, L[0].second });
	visited[L[0].first][L[0].second] = true;
	while (!BFS())
	{
		ans++;
		next_ice.clear();
		for (auto p : ice)
		{
			arr[p.first][p.second] = '.';
		}
		for (auto p : ice)
		{
			FUP(k, 0, 3)
			{
				int ny = p.first + dy[k];
				int nx = p.second + dx[k];
				if (ny < 0 || nx < 0 || ny >= R || nx >= C ) continue;
				// ������ ���� ���� üũ
				if (arr[ny][nx] == 'X' && !check[ny][nx])
				{
					check[ny][nx] = true;
					next_ice.push_back({ ny, nx });
				}
				// ������ �� �� �ִ� ������ üũ
				if (visited[ny][nx] && !visited[p.first][p.second])
				{
					visited[p.first][p.second] = true;
					q.push({ p.first, p.second });
				}
			}
		}
		ice = next_ice;
	}
	COUT(ans);

	return 0;
}