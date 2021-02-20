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

int N, C, arr[30];
ll ans = 0;
vector<int> L, R;

void leftSolve(int idx, int num)
{
	if (num > C) return;
	if (idx == 15 || idx >= N)
	{
		L.push_back(num);
		return;
	}
	leftSolve(idx + 1, num + arr[idx]);
	leftSolve(idx + 1, num);
}

void rightSolve(int idx, int num)
{
	if (num > C) return;
	if (idx >= N)
	{
		R.push_back(num);
		return;
	}
	rightSolve(idx + 1, num + arr[idx]);
	rightSolve(idx + 1, num);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(N, C);
	FUP(i, 0, N - 1) CIN(arr[i]);
	leftSolve(0, 0);
	rightSolve(15, 0);
	sort(ALL(L));
	sort(ALL(R));
	for (int l : L)
	{
		int r = upper_bound(ALL(R), C - l) - R.begin();
		ans += r;
	}
	COUT(ans);


	return 0;
}