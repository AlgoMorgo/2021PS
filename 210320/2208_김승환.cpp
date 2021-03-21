#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int N, M;
    cin >> N >> M;
    vector<int> v(N+1);
    for (int i=1; i<=N; ++i)
    {
        cin >> v[i];
        v[i] += v[i-1];
    }
    vector<int> m(N+1);
    for (int i=1; i<=N; ++i)
        m[i] = min(v[i], m[i-1]);

    int answer = 0;
    for (int i=M; i<=N; ++i)
        answer = max(v[i] - m[i-M], answer);
    cout << answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}