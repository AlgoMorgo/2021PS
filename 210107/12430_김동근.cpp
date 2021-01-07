#define iii
#ifdef iii
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <cmath>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;


struct info {
	int p, s;

};
info PS[1001];

bool cmp(info& a, info& b) {
	/*if (a.p == b.p) return a.s > b.s;
	else return a.p > b.p;*/
	return (a.p + a.s) < (b.p + b.s);
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	for(int T = 1 ; T <= t; T++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> PS[i].p >> PS[i].s;
		}

		sort(PS, PS + n, cmp);

		int start = PS[0].p;
		int end = PS[0].s;

		for (int i = 1; i < n; i++) {
			if (start >= PS[i].s) {
				end += PS[i].s;
				start = PS[i].p;
			}
            else if (end <= PS[i].p) {
                end += PS[i].s;
                start = PS[i].p;
            }
			else {
				if (end < PS[i].s) {
					end = PS[i].s;
					start = PS[i].p;
				}
				else if (end == PS[i].s && start < PS[i].p) start = PS[i].p;
			}
		}
		cout << "Case #" + to_string(t) + ": " + to_string(end) << '\n';
	}

	return 0;
}

#else
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve()
{
    int N;
    cin >> N;

    vector<pair<int, int>> ps;
    for (int i = 0; i < N; ++i)
    {
        int p, s;
        cin >> p >> s;
        ps.emplace_back(p, s);
    }
    // p + s�� ���� (�ķ��� �ִ� �� ������ ����, �̷��� �ִ��� ������ ������ �����)
    sort(ps.begin(), ps.end(), [](auto a, auto b) { return a.first + a.second < b.first + b.second; });

    vector<bool> dp(ps[N - 1].first + ps[N - 1].second + 1);
    dp[0] = dp[ps[0].second] = true;
    for (int i = 1; i < N; ++i)
    {
        for (int j = ps[i].first; j >= 0; --j)
        {
            if (dp[j])
                dp[j + ps[i].second] = true;
            /*
             * dp[j + ps[i].second] = dp[j] �ϴ� �ð��ʰ�;;
             * ���� ������ ���� ��ü�� ���̴� �������� ����
             * �����Ϸ��� ����ȭ ���� �� �˾Ҵµ� �ƴѰ���
             * if�� �ٿ��� ������� jump�� �ּ�ȭ���ڰ� �����ߴµ�,
             * jump�� �Ͼ���� ���� ��ü�� �پ��� �ξ� ����������
             * ���߿� godbolt�� �־ �м��غ���
             */
        }
    }

    int i;
    for (i = ps[N - 1].first + ps[N - 1].second; i >= 0; --i)
    {
        if (dp[i])
            break;
    }
    cout << i << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}


#endif