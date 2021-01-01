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
vector<pair<int, int>> picture; // {�л�, �ð�}
set<int> answer;	// ���� ������ �ڵ� �����ϱ� ����.

// �л��� ��õ���� ���� ����. ���� ��쿡�� �Խõ� �ð����� ��
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
		if (cnt[idx]++) continue;	// cnt�� 0�� �ƴ� ���� ������ ������ �ɷ�����.
		if (picture.size() < N)
		{
			picture.push_back({ idx, time }); // ����Ʋ�� �� ���� ������ �ٷ� �߰�
		}
		else
		{
			sort(ALL(picture), comp); // ����Ʋ�� �� �� ���� ���õ� �������� ��������.
			cnt[picture[0].first] = 0; // ���� �� ���� ù ��° ����Ʋ�� ����
			picture[0] = { idx, time };
		}
	}
	for (auto p : picture)
	{
		answer.insert(p.first); // ���������� ����Ʋ�� �ɸ� �л����� �־���.
	}
	for (int num : answer)
	{
		COUT2(num, "");
	}

	return 0;
}