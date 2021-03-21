#include <bits/stdc++.h>
using namespace std;

int N, T, K[1001], S[1001], memo[1001][10001];
// memo [ index ] [ time ]
void solve()
{
    cin >> N >> T;
    for (int i=1; i<=N; ++i)
        cin >> K[i] >> S[i];
    for (int i=1; i<=N; ++i)
    {
        for (int w=1; w<=T; ++w)
        {
            if (K[i] > w)
                memo[i][w] = memo[i-1][w];
            else
                memo[i][w] = max(memo[i-1][w], memo[i-1][w-K[i]] + S[i]);
        }
    }
    cout << memo[N][T];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}