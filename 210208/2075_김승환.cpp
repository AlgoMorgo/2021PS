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
    int N, t;
    cin >> N;
    priority_queue<int> pq;
    for (int i=0; i<N; ++i)
    {
        cin >> t;
        pq.push(-t);
    }
    for (int i=N; i<N*N; ++i)
    {
        cin >> t;
        pq.push(-t);
        pq.pop();
    }
    cout << -pq.top();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}