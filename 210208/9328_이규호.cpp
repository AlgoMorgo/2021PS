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

int T, N, M;
string key;
bool visited[102][102];
char arr[102][102];

bool isKey(char ch)
{
	if (ch >= 'a' && ch <= 'z') return true;
	else return false;
}

bool isDoor(char ch)
{
	if (ch >= 'A' && ch <= 'Z') return true;
	else return false;
}

int small(char ch)
{
	return 1 << (ch - 'a');
}

int big(char ch)
{
	return 1 << (ch - 'A');
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(T);
	while (T--)
	{
		int cnt = 0;
		int K = 0; // 가지고 있는 열쇠 저장
		CIN2(N, M);
		FUP(i, 1, N)
		{
			FUP(j, 1, M)
			{
				CIN(arr[i][j]);
			}
		}
		CIN(key);
		if (key != "0")
		{
			for (char ch : key)
			{
				K |= small(ch); // 비트 연산으로 열쇠 추가
			}
		}

		// '.'으로 패딩 씌우기
		FUP(i, 0, N + 1)
		{
			for (int j : {0, M + 1})
			{
				arr[i][j] = '.';
			}
		}
		for (int i : {0, N + 1})
		{
			FUP(j, 0, M + 1)
			{
				arr[i][j] = '.';
			}
		}
		queue<pair<int, int>> q;
		MS(visited, false);
		visited[0][0] = true;
		q.push({ 0, 0 });
		while (!q.empty())
		{
			int y = q.front().first;
			int x = q.front().second;
			if (arr[y][x] == '$') // 문서면 가져오고 '.'으로 바꾸기
			{
				cnt++;
				arr[y][x] = '.';
			}
			q.pop();
			if (!visited[y][x]) continue; // key를 주워서 초기화됐으면, 넘김
			FUP(i, 0, 3)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || nx < 0 || ny > N + 1 || nx > M + 1 || arr[ny][nx] == '*' || visited[ny][nx]) continue;
				if (isKey(arr[ny][nx]))
				{
					if ((K | small(arr[ny][nx])) - K != 0) // 없는 키일때,
					{
						MS(visited, false); // visited 배열 초기화 후 다시 순회
						K |= small(arr[ny][nx]); // 열쇠 추가
					}
					visited[ny][nx] = true;
					arr[ny][nx] = '.'; // 주웠으면 '.'으로 바꾸기
					q.push({ ny, nx });
				}
				else if (isDoor(arr[ny][nx]))
				{
					if ((K & big(arr[ny][nx])) == 0) continue; // K에 없으면 못들어간다
					arr[ny][nx] = '.';
					visited[ny][nx] = true;
					q.push({ ny, nx });
				}
				else
				{
					visited[ny][nx] = true;
					q.push({ ny, nx });
				}
			}
		}
		COUT(cnt);
		ENDL;
	}

	return 0;
}