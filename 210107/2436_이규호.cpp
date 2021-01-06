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

int gcd(int x, int y)
{
	if (x < y) swap(x, y);
	int rest;
	while (y)
	{
		rest = x % y;
		x = y;
		y = rest;
	}
	return x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int A, B;
	CIN2(A, B);
	int num = B / A;
	int x = sqrt(num);
	// 최소공배수 나누기 최대공약수 값을 num이라고 한다.
	// 곱하면 num이 되는 두 서로소 값을 각각 최대공약수에 곱해주면 정답임.
	// 합이 가장 작은 수를 구하기 위해서는 루트 num에 가장 가까운 수를 구하면 됨.
	while (true)
	{
		if (num % x == 0 && gcd(x, num / x) == 1)
		{
			COUT2(A * x, A * (num / x));
			break;
		}
		x--;
	}

	return 0;
}