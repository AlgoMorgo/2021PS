#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int N, K, S;
    cin >> N >> K >> S;
    vector<pair<int, int>> v(N);
    for (auto& p : v)
        cin >> p.first >> p.second;
    sort(v.begin(), v.end());

    int end = lower_bound(v.begin(), v.end(), make_pair(S+1, 0)) - v.begin(), x = K, answer = 0;
    for (int i=0; i<end;)
    {
        if (x == K)
            answer += 2 * (S - v[i].first);
        if (v[i].second <= x)
        {
            x -= v[i].second;
            i++;
        }
        else
        {
            v[i].second -= x;
            x = K;
        }
    }
    x = K;
    for (int i=N-1; i>=end;)
    {
        if (x == K)
            answer += 2 * (v[i].first - S);
        if (v[i].second <= x)
        {
            x -= v[i].second;
            i--;
        }
        else
        {
            v[i].second -= x;
            x = K;
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