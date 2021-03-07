#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int N, K;
    cin >> N;
    vector<int> v(N);
    for (int& i : v)
        cin >> i;
    cin >> K;

    int m = 51;
    vector<int> p(N);
    p[0] = v[0];
    for (int i=1; i<N; ++i)
    {
        m = min(m, v[i]);
        p[i] = min(p[i-1], v[i]);
    }

    int digit;
    if (v[0] < m)
    {
        if (m > K)
        {
            cout << '0';
            return;
        }
        digit = 1 + (K-m)/v[0];
    }
    else
        digit = K/m;

    vector<int> answer(digit);
    for (int i=0; i<digit; ++i)
    {
        for (int j=N-1; j>=0; --j)
        {
            if (K >= v[j] && (K - v[j]) / p[j] >= digit-i-1)
            {
                K -= v[j];
                answer[i] = j;
                break;
            }
        }
    }
    for (int i : answer)
        cout << i;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}