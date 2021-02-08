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

string str, ans = "";
stack<char> S;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(str);
	for (char ch : str)
	{
		if ('A' <= ch && ch <= 'Z') ans += ch;
		else if (ch == '(')
		{
			S.push(ch);
		}
		else if (ch == ')')
		{
			while (!S.empty() && S.top() != '(')
			{
				ans += S.top();
				S.pop();
			}
			S.pop();
		}
		else if (ch == '*' || ch == '/')
		{
			while (!S.empty() && (S.top() == '*' || S.top() == '/'))
			{
				ans += S.top();
				S.pop();
			}
			S.push(ch);
		}
		else
		{
			while (!S.empty() && S.top() != '(')
			{
				ans += S.top();
				S.pop();
			}
			S.push(ch);
		}
	}
	while (!S.empty())
	{
		ans += S.top();
		S.pop();
	}

	COUT(ans);

	return 0;
}