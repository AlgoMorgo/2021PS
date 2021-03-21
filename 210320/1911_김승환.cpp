#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int N, L;
    cin >> N >> L;
    vector<pair<int, int>> ps(N);
    for (auto& p : ps)
        cin >> p.first >> p.second;
    sort(ps.begin(), ps.end());

    int last, answer = 1;
    last = ps[0].first + L;
    for (int i=0; i<N;)
    {
        if (ps[i].second <= last)
            i++;
        else if (ps[i].first > last)
        {
            answer++;
            last = ps[i].first + L;
        }
        else
        {
            answer++;
            last += L;
        }
    }

    cout << answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}