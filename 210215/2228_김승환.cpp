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
    int N, M;
    cin >> N >> M;
    vector<int> num(N+1);
    for (int i=0; i<N; ++i)
        cin >> num[i+1];
    for (int i=1; i<N+1; ++i)
        num[i] += num[i-1];
    vector<vector<int>> dp(N+1, vector<int>(M+1, -1e7));
    function<int (int, int)> calc = [&] (int index, int count)
    {
        if (index >= N || count == 0)
            return 0;
        if (dp[index][count] > -1e7)
            return dp[index][count];

        if (index <= N-2*count)
            dp[index][count] = calc(index+1, count);
        for (int i=index+1; i<=N-2*(count-1); ++i)
        {
            if (num[i] - num[index] + calc(i+1, count-1) > dp[index][count])
                dp[index][count] = num[i] - num[index] + calc(i+1, count-1);
        }
        return dp[index][count];
    };
    cout << calc(0, M);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}