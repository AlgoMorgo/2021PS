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
    int N;
    cin >> N;
    vector<int> t(N);
    vector<vector<int>> f(N);
    for (int i=0; i<N; ++i)
    {
        cin >> t[i];
        int temp;
        cin >> temp;
        while (temp != -1)
        {
            f[i].push_back(temp-1);
            cin >> temp;
        }
    }
    vector<bool> check(N);
    for (int i=0; i<N; ++i)
    {
        int j;
        for (j=0; j<N; ++j)
        {
            if (check[j])
                continue;
            bool flag = true;
            for (int k : f[j])
            {
                if (!check[k])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                break;
        }
        check[j] = true;
        int temp = 0;
        for (int k : f[j])
            temp = max(t[k], temp);
        t[j] += temp;
    }
    for (int answer : t)
        cout << answer << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}