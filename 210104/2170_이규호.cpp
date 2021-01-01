#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define FUP(i, a, b) for(int i = a; i <= b; i++)
#define FDOWN(i, a, b) for(int i = a; i >= b; i--)
#define MS(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define CIN(a) cin >> a
#define CIN2(a, b) cin >> a >> b
#define CIN3(a, b, c) cin >> a >> b >> c
#define COUT(a) cout << a
#define COUT2(a, b) cout << a << ' ' << b
#define COUT3(a, b, c) cout << a << ' ' << b << ' ' << c
#define ENDL cout << '\n'
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int N, ans = 0;
pair<int, int> line[1000000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	FUP(i, 0, N - 1) CIN2(line[i].first, line[i].second);
	sort(line, line + N);	// 왼쪽 좌표를 기준으로 정렬
	int before = -1e9;		// 이전에 어디까지 그어져 있는지
	FUP(i, 0, N - 1)
	{
		if (before <= line[i].first)	// 이전에 그은 선과 겹치지 않는 경우
		{
			ans += (line[i].second - line[i].first);
			before = line[i].second;
		}	// 해당 line의 길이를 더하고, before을 초기화
		else if (line[i].second > before)	// 겹치는데, 오른쪽이 좌표가 더 큰 경우
		{
			ans += (line[i].second - before);
			before = line[i].second;
		}	// 현재 line에서 겹치는 부분을 제거 후 더함.
		//나머지 경우는 고려할 필요 없음
	}
	COUT(ans);


	return 0;
}