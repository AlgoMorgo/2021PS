#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <queue>
#include <set>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> jew(N);
    for (auto& p : jew)
    {
        cin >> p.second >> p.first;
        p.second = -p.second;
    }
    multiset<int> bag;
    for (int i=0; i<K; ++i)
    {
        int w;
        cin >> w;
        bag.insert(w);
    }
    sort(jew.begin(), jew.end());

    ll answer = 0;
    while (!jew.empty() && !bag.empty())
    {
        const int mass = -jew.back().second, value = jew.back().first;
        const auto iter = bag.lower_bound(mass);
        jew.pop_back();

        if (iter != bag.end())
        {
            bag.erase(iter);
            answer += value;
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