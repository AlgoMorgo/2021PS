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

int N, num, T[501], ans[501];
vector<int> before[501];

int DFS(int node)
{
	if (ans[node] != -1) return ans[node];
	int max_time = 0;
	for (int b : before[node])
	{
		max_time = max(max_time, DFS(b));
	}
	return ans[node] = T[node] + max_time;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(ans, -1);
	CIN(N);
	FUP(i, 1, N)
	{
		CIN(T[i]);
		while(true)
		{
			CIN(num);
			if (num == -1) break;
			before[i].push_back(num);
		}
	}
	FUP(i, 1, N)
	{
		if(ans[i] == -1) DFS(i);
		COUT(ans[i]);
		ENDL;
	}

	return 0;
}