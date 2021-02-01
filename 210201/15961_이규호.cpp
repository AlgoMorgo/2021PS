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

int N, D, K, C, ans = 0, arr[3003001];
map<int, int> cnt;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN2(N, D);
	CIN2(K, C);
	FUP(i, 1, N) CIN(arr[i]);
	FUP(i, N + 1, N + K) arr[i] = arr[i - N];
	int L = 1, R = K;
	cnt[C]++;
	FUP(i, L, R) cnt[arr[i]]++;
	ans = cnt.size();
	while (L <= N)
	{
		cnt[arr[++R]]++;
		if (--cnt[arr[L++]] == 0) cnt.erase(arr[L - 1]);
		ans = max(ans, (int)cnt.size());
	}
	COUT(ans);

	return 0;
}