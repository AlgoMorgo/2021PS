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
    int N, num;
    cin >> N >> num;
    vector<vector<ll>> v(21, vector<ll>(2));
    v[num][0] = 1;
    for (int i=1; i<N-1; ++i)
    {
        cin >> num;
        for (int j=0; j<21; ++j)
        {
            if (j - num >= 0)
                v[j - num][1] += v[j][0];
            if (j + num < 21)
                v[j + num][1] += v[j][0];
        }
        for (int j=0; j<21; ++j)
        {
            v[j][0] = v[j][1];
            v[j][1] = 0;
        }
    }
    cin >> num;
    cout << v[num][0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}