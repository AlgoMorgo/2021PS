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
    int N, C, M;
    cin >> N >> C >> M;
    vector<tuple<int, int, int>> v(M);
    for (auto& t : v)
        cin >> get<1>(t) >> get<0>(t) >> get<2>(t);
    sort(v.begin(), v.end());
    vector<int> res(N+1);
    int answer = 0;
    for (auto& t : v)
    {
        int box = get<2>(t);
        for (int i=get<1>(t); i<get<0>(t); ++i)
            box = min(C - res[i], box);
        answer += box;
        for (int i=get<1>(t); i<get<0>(t); ++i)
            res[i] += box;
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