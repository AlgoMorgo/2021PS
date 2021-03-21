#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    ll N, X;
    cin >> N >> X;
    if (X < N || N*26 < X)
    {
        cout << '!';
        return;
    }
    ll L = (X-N)/25;
    for (ll i=0; i<N-L-1; ++i)
        cout << 'A';
    if (N-L > 0)
        cout << (char)(X-N-L*25+'A');
    for (ll i=0; i<L; ++i)
        cout << 'Z';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}