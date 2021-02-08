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

int N, M, L, parent[51], know[50], ans = 0;
vector<int> party[50];

int find(int x)
{
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void update(int x, int y)
{
	if (x > y) swap(x, y);
	x = find(x);
	y = find(y);
	parent[y] = x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN3(N, M, L);
	FUP(i, 1, N) 
		parent[i] = i;
	FUP(i, 0, L - 1) 
		CIN(know[i]);
	FUP(i, 1, L - 1) 
		update(know[i - 1], know[i]);
	FUP(i, 0, M - 1)
	{
		CIN(L);
		party[i].resize(L);
		FUP(j, 0, L - 1) 
			CIN(party[i][j]);
		FUP(j, 1, L - 1) 
			update(party[i][j], party[i][j - 1]);
	}

	int P = find(know[0]); // 아는 사람들의 parent 값
	FUP(i, 0, M - 1)
	{
		int flag = 1;
		for (int person : party[i])
		{
			if (find(person) == P)
			{
				flag = 0;
				break;
			}
		}
		ans += flag;
	}
	COUT(ans);

	return 0;
}