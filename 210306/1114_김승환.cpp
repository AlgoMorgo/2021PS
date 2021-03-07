#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int L, K, C;
    cin >> L >> K >> C;
    C = min(K, C);
    vector<int> v(K);
    for (int& i : v)
        cin >> i;
    sort(v.begin(), v.end());

    auto calc = [&] (int k) -> int
    {
        int back, count = 1;
        auto ptr = lower_bound(v.begin(), v.end(), L-k);
        if (ptr == v.end())
            return -1;
        back = *ptr;
        while (back > k)
        {
            ptr = lower_bound(v.begin(), ptr, back - k);
            if (*ptr == back)
                return -1;
            back = *ptr;
            if (++count > C)
                return -1;
        }
        if (count < C)
            return v[0];
        return back;
    };
    int start = 0, end = L;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (calc(mid) != -1)
            end = mid;
        else
            start = mid+1;
    }
    cout << end << ' ' << calc(end);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}