#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int N;
    cin >> N;
    vector<pair<int, int>> v(N);
    for (auto& p : v)
        cin >> p.first >> p.second;
    int L, P;
    cin >> L >> P;
    sort(v.begin(), v.end());

    int answer = 0;
    priority_queue<int> pq;
    for (int i=0; i<N; ++i)
    {
        while (v[i].first > P)
        {
            if (P >= L)
                break;
            if (pq.empty())
            {
                cout << -1;
                return;
            }
            P += pq.top();
            pq.pop();
            answer++;
        }
        pq.push(v[i].second);
    }
    while (P < L && !pq.empty())
    {
        P += pq.top();
        pq.pop();
        answer++;
    }
    cout << (P >= L ? answer : -1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}