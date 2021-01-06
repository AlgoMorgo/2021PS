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

ll N, arr[100000], ans = 0;
set<int> seller, buyer;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	FUP(i, 0, N - 1)
	{
		CIN(arr[i]);
		if (arr[i] > 0) seller.insert(i);
		else buyer.insert(i);
	}	// +와 -를 분할. 각 인덱스를 저장(투 포인터)
	auto i = seller.begin();
	auto j = buyer.begin();
	while (i != seller.end() && j != buyer.end())
	{
		// 합은 무조건 0이기에 전처리 필요 없음.
		if (arr[*i] > abs(arr[*j]))
		{
			arr[*i] += arr[*j];
			ans += abs(arr[*j] * (*j - *i));
			j++;
		}
		else if (arr[*i] < abs(arr[*j]))
		{
			arr[*j] += arr[*i];
			ans += (arr[*i] * abs(*j - *i));
			i++;
		}
		else
		{
			ans += (arr[*i] * abs(*j - *i));
			i++; j++;
		}
	}
	COUT(ans);


	return 0;
}