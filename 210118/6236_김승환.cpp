#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int N, M;
    cin >> N >> M;
    vector<int> v(N);
    for (int& i : v)
        cin >> i;

    int l = *max_element(v.begin(), v.end()), r = (N/M+1)*l;
    while (l < r)
    {
        int mid, remain, count;
        mid = remain = (l+r)/2;
        count = 1;
        for (int i : v)
        {
            if (i <= remain)
                remain -= i;
            else
            {
                remain = mid - i;
                count++;
            }
        }

        if (count <= M)
            r = mid;
        else
            l = mid+1;
    }
    cout << l;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}