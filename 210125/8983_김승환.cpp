#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int M, N, L;
    cin >> M >> N >> L;
    vector<int> s(M);
    for (int& i : s)
        cin >> i;
    vector<pair<int, int>> a(N);
    for (auto& p : a)
        cin >> p.first >> p.second;

    int answer = 0;
    sort(s.begin(), s.end());
    for (int i=0; i<N; ++i)
    {
        auto up = lower_bound(s.begin(), s.end(), a[i].first);
        up = up == s.end() ? s.end()-1 : up;
        auto low = lower_bound(s.rbegin(), s.rend(), a[i].first, greater<>());
        low = low == s.rend() ? s.rend()-1 : low;
        if (min(abs(*up - a[i].first), abs(*low - a[i].first)) + a[i].second <= L)
            answer++;
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