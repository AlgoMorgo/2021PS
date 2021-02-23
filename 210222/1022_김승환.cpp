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
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    auto calc = [] (int x, int y) -> int
    {
        if (x == 0 && y == 0)
            return 1;
        if (x < 0 && abs(y) <= -x)
            return 4*x*x+1 + y-x;
        if (y < 0 && abs(x) <= -y)
            return 4*y*y+1 + y-x;
        if (x > y)
            return (2*x-1)*(2*x-1) + x-y;
        return (2*y+1)*(2*y+1) + x-y;
    };
    auto digit = [] (int k) -> int
    {
        int res = 0;
        while (k)
        {
            k /= 10;
            res++;
        }
        return res;
    };

    int l = digit(calc(c1, r1));
    l = max(digit(calc(c2, r1)), l);
    l = max(digit(calc(c1, r2)), l);
    l = max(digit(calc(c2, r2)), l);
    for (int i=r1; i<=r2; ++i)
    {
        for (int j=c1; j<c2; ++j)
        {
            int temp = calc(j, i);
            for (int k=0; k<l-digit(temp); ++k)
                cout << ' ';
            cout << temp << ' ';
        }
        int temp = calc(c2, i);
        for (int k=0; k<l-digit(temp); ++k)
            cout << ' ';
        cout << temp << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}