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
    int N, K;
    cin >> N >> K;
    vector<int> v(N), sub(N);
    for (int i=0; i<N; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());
    for (int i=0; i<N-1; ++i)
        sub[i] = v[i] - v[i+1];
    sort(sub.begin(), sub.end());
    int answer = v.back() - v.front();
    for (int i=0; i<K-1 && i<N; ++i)
        answer += sub[i];
    cout << answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}