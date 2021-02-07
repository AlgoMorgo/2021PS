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
    long long N, A;
    cin >> N >> A;
    cout << N - A << ' ';

    function<tuple<ll, ll, ll> (ll, ll)> exteuc = [&] (ll a, ll b)
    {
        if (b == 0)
            return make_tuple(a, 1LL, 0LL);
        ll g, x, y;
        tie(g, x, y) = exteuc(b, a%b);
        return make_tuple(g, y, x-(a/b)*y);
    };
    ll g, x, y;
    tie(g, x, y) = exteuc(A, N);
    if (x < 0)
        x += N;
    cout << (g == 1 ? x : -1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}