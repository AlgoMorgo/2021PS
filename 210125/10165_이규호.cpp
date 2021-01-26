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
typedef pair<pair<int, int>, int> PP;


int N, M;
vector<PP> arr;
set<int> ans;

bool comp(PP a, PP b)
{
	if (a.first.first == b.first.first)
		return a.first.second > b.first.second;
	return a.first.first < b.first.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(N, M);
	FUP(i, 1, M)
	{
		int a, b;
		CIN2(a, b);
		if (a < b) arr.push_back({ { a, b }, i });
		else
		{
			arr.push_back({ {a - N, b}, i });
			arr.push_back({ {a, b + N}, i });
		}
	}
	sort(ALL(arr), comp);
	ans.insert(arr[0].second);
	int before = arr[0].first.second;
	FUP(i, 1, arr.size() - 1)
	{
		if (before < arr[i].first.second)
		{
			ans.insert(arr[i].second);
			before = arr[i].first.second;
		}
	}
	for (int idx : ans)
	{
		COUT2(idx, "");
	}

	return 0;
}