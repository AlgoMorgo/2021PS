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

int N, M, K, a, b, parent[10001];
ll arr[10001], ans = 0, visited[10001];

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

	CIN3(N, M, K);
	FUP(i, 1, N)
	{
		CIN(arr[i]);
		visited[i] = 0;
		parent[i] = i;
	}
	while (M--)
	{
		CIN2(a, b);
		update(a, b);
	}
	FUP(i, 1, N)
	{
		int p = find(i);
		if (visited[p] == 0)
		{
			ans += arr[i];
			visited[p] = arr[i];
		}
		else if(visited[p] > arr[i])
		{
			ans = ans - visited[p] + arr[i];
			visited[p] = arr[i];
		}
	} 
	ans <= K ? COUT(ans) : COUT("Oh no");

	return 0;
}