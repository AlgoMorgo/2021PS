#include <bits/stdc++.h>
using namespace std;
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define CIN(a) cin >> a;
#define CIN3(a, b, c) cin >> a >> b >> c
#define COUT(a) cout << a
#define ENDL cout << '\n'
int dy[9] = { 0, 1, 1, 1, 0, -1, -1, -1, 0 };
int dx[9] = { 0, -1, 0, 1, 1, 1, 0, -1, -1 };

struct Bug
{
	int x, y, d;
	Bug() {}
};

int N, max_num = 0, min_time = 0;
Bug bug[5001];
int table[2000001], tmp[2000001];

void solve(Bug A, Bug B, int idx)
{
	int mother, son, t;
	if (dx[A.d] == dx[B.d]) // x 움직임이 같은 경우
	{
		if (A.x != B.x) return; // x 좌표가 다르면 불가능 
		son = A.y - B.y;
		mother = dy[B.d] - dy[A.d];
		if (mother == 0) return; // x좌표가 같으므로 y 좌표는 다름
		else if (son % mother != 0) return; // 못 만나는 경우
		t = son / mother;
	}
	else // x 움직임이 다른 경우
	{
		son = A.x - B.x;
		mother = dx[B.d] - dx[A.d];
		if (son % mother != 0) return;
		t = son / mother;
		if (A.y + dy[A.d] * t != B.y + dy[B.d] * t) return;
	}
	if (t < 0) return;
	if (tmp[t] != idx)
	{
		tmp[t] = idx;
		table[t] = 2;
	}
	else table[t]++;
	if (table[t] > max_num)
	{
		max_num = table[t];
		min_time = t;
	}
	else if (table[t] == max_num) min_time = min(min_time, t);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	FUP(i, 1, N) CIN3(bug[i].x, bug[i].y, bug[i].d);
	FUP(i, 1, N - 1)
	{
		FUP(j, i + 1, N)
		{
			solve(bug[i], bug[j], i);
		}
	}
	COUT(max_num);
	ENDL;
	COUT(min_time);

	return 0;
}