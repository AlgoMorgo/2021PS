#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <queue>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int N, C;
    cin >> N >> C;
    vector<int> v(N);
    for (int& i : v)
        cin >> i;
    vector<int> half;
    for (int i=0; i<(1 << N/2); ++i)
    {
        ll acc = 0;
        for (int x=0; x<N/2; ++x)
        {
            if (1 << x & i)
                acc += v[x];
        }
        if (acc <= C)
            half.push_back(acc);
    }
    sort(half.begin(), half.end());
    int answer = 0;
    for (int i=0; i<(1 << (N/2+N%2)); ++i)
    {
        ll acc = 0;
        for (int x=N/2; x<N; ++x)
        {
            if (1 << (x-N/2) & i)
                acc += v[x];
        }
        if (acc <= C)
            answer += upper_bound(half.begin(), half.end(), C - acc) - half.begin();
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