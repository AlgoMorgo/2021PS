#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <queue>

using namespace std;
using ll = long long;

void solve()
{
    int N, M, k;
    cin >> N >> M;
    vector<bool> q(N);
    cin >> k;
    for (int i=0; i<k; ++i)
    {
        int t;
        cin >> t;
        q[t] = true;
    }
    vector<vector<int>> v;
    for (int i=0; i<M; ++i)
    {
        cin >> k;
        v.emplace_back(k);
        for (int j=0; j<k; ++j)
            cin >> v[i][j];
    }
    vector<bool> check(M);
    while (true)
    {
        int i;
        for (i=0; i<M; ++i)
        {
            if (check[i])
                continue;
            for (int p : v[i])
            {
                if (q[p])
                {
                    check[i] = true;
                    break;
                }
            }
            if (check[i])
                break;
        }
        if (i == M)
            break;
        for (int p : v[i])
            q[p] = true;
    }
    int answer = 0;
    for (bool b : check)
        answer += !b;
    cout << answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}