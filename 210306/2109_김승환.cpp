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
    {
        cin >> p.first >> p.second;
        p.first = -p.first;
        p.second--;
    }
    sort(v.begin(), v.end());

    int answer = 0;
    vector<bool> visited(10000);
    for (auto& p : v)
    {
        for (int i=p.second; i>=0; --i)
        {
            if (!visited[i])
            {
                visited[i] = true;
                answer -= p.first;
                break;
            }
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