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
    int N;
    cin >> N;
    vector<pair<int, int>> v(N);
    for (auto& p : v)
        cin >> p.first >> p.second;
    sort(v.begin(), v.end());
    auto comp = [] (auto& a, auto& b) { return a.second > b.second; };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
    int time = 1;
    for (auto& p : v)
    {
        if (p.first > time)
            time = p.first;
        pq.push(p);
        if (pq.size() > time)
            pq.pop();
    }
    ll answer = 0;
    while (!pq.empty())
    {
        answer += pq.top().second;
        pq.pop();
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