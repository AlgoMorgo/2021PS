#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int N;
    cin >> N;

    vector<int> v(N, 1);
    auto check = [&] (int size) -> bool
    {
        if (size == 1)
            return true;
        for (int i=0; i<size; ++i)
        {
            for (int l=1; i-l+1 >= 0 && i+l < size; ++l)
            {
                vector<int> a(l), b(l);
                for (int j=0; j<l; ++j)
                {
                    a[l-j-1] = v[i-j];
                    b[j] = v[i+j+1];
                }

                bool flag = true;
                for (int j=0; j<l; ++j)
                {
                    if (a[j] != b[j])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    return false;
            }
        }
        return true;
    };
    function<bool (int)> dfs = [&] (int depth)
    {
        if (depth == N)
            return check(depth);

        v[depth] = 1;
        if (check(depth) && dfs(depth+1))
            return true;
        v[depth] = 2;
        if (check(depth) && dfs(depth+1))
            return true;
        v[depth] = 3;
        return dfs(depth+1);
    };
    dfs(0);
    for (int i : v)
        cout << i;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}