#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int T, N, target = 0;
    cin >> T >> N;
    vector<int> v(N);
    for (int& i : v)
    {
        cin >> i;
        target += i;
    }

    if (target <= T)
    {
        cout << 0;
        int time = v[0];
        for (int i=1; i<N; ++i)
        {
            cout << ' ' << time;
            time += i;
        }
        return;
    }

    int up = v[0];
    vector<vector<bool>> dp(N, vector<bool>(target+1));
    dp[0][0] = dp[0][v[0]] = true;
    for (int i=1; i<N; ++i)
    {
        for (int j=0; j<=up; ++j)
        {
            if (dp[i-1][j])
            {
                dp[i][j] = true;
                dp[i][j+v[i]] = true;
            }
        }
        up += v[i];
    }
    for (up=target-T; up<=T; ++up)
    {
        if (dp[N-1][up])
            break;
    }

    vector<int> answer(N, -1);
    int time = 0, index = N-1;
    while (up > 0)
    {
        if (index == -1)
        {
            answer[0] = time;
            break;
        }
        if (!dp[index][up])
        {
            answer[index+1] = time;
            time += v[index+1];
            up -= v[index+1];
        }
        index--;
    }

    time = 0;
    for (int i=N-1; i>=0; --i)
    {
        if (answer[i] != -1)
            continue;
        answer[i] = time;
        time += v[i];
    }

    cout << answer[0];
    for (int i=1; i<N; ++i)
        cout << ' ' << answer[i];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}