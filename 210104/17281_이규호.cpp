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

int N, scoring[51][9], ans = 0, base[3]; // 1, 2, 3루를 3칸 배열로 처리
vector<int> permut = { 1, 2, 3, 4, 5, 6, 7, 8 }; // 순열 벡터

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	CIN(N);
	FUP(i, 1, N)
	{
		FUP(j, 0, 8)
		{
			CIN(scoring[i][j]);
		}
	}
	do
	{
		int score = 0;
		int idx = -1; // 현재 히터가 몇 번 타자인지 저장
		FUP(i, 1, N) //1회부터 N회까지.
		{
			/*
				아웃 카운트 초기화.
				batter : idx번 타자에 해당하는 인덱스
				bat : 해당 타자가 이번회에 치게 될 안타
			*/
			int out = 0, batter, bat;
			base[0] = base[1] = base[2] = 0; // 베이스는 비워둠.
			while (out < 3) // 3아웃
			{
				idx = (idx + 1) % 9;
				/*
					4번타자는 무조건 0번째 사람임
					따라서 3보다 idx가 크면 idx - 1을 해줘야 한다.(4번이 비기 때문)
				*/
				if (idx < 3) batter = permut[idx];
				else if (idx == 3) batter = 0;
				else batter = permut[idx - 1];
				bat = scoring[i][batter];
				if (bat == 0)
				{
					out++;
					continue;
				}
				FDOWN(i, 2, 0) // 3루부터 순회하면서 진루시킴.
				{
					if (!base[i]) continue;
					if (i + bat > 2) score++;	// 2보다 클 시 득점
					else(base[i + bat] = 1);	// 아닌 경우 진루
					base[i] = 0;
				}
				if (bat == 4) score++;
				else base[bat - 1] = 1;	// 홈런이 아니면 베이스를 채워줌.
			}
		}
		ans = max(ans, score);
	} while (next_permutation(ALL(permut)));
	COUT(ans);

	return 0;
}