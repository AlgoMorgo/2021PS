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

int N, M, cnt[101], idx;
vector<pair<int, int>> picture; // {학생, 시간}
set<int> answer;	// 최종 정답을 자동 정렬하기 위해.

// 학생의 추천수를 먼저 비교함. 같은 경우에는 게시된 시간으로 비교
bool comp(pair<int, int> A, pair<int, int> B)
{
	if (cnt[A.first] == cnt[B.first])
	{
		return A.second < B.second;
	}
	return cnt[A.first] < cnt[B.first];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	MS(cnt, 0);
	CIN2(N, M);
	FUP(time, 1, M)
	{
		CIN(idx);
		if (cnt[idx]++) continue;	// cnt가 0이 아닌 경우는 무조건 사진이 걸려있음.
		if (picture.size() < N)
		{
			picture.push_back({ idx, time }); // 사진틀이 꽉 차지 않으면 바로 추가
		}
		else
		{
			sort(ALL(picture), comp); // 사진틀이 꽉 찬 경우는 제시된 조건으로 정렬해줌.
			cnt[picture[0].first] = 0; // 정렬 후 제일 첫 번째 사진틀을 제거
			picture[0] = { idx, time };
		}
	}
	for (auto p : picture)
	{
		answer.insert(p.first); // 최종적으로 사진틀에 걸린 학생들을 넣어줌.
	}
	for (int num : answer)
	{
		COUT2(num, "");
	}

	return 0;
}