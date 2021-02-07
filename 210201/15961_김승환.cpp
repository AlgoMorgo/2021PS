#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

void solve()
{
    int N, d, k, c;
    cin >> N >> d >> k >> c;
    vector<int> arr(N);
    for (int& i : arr)
        cin >> i;
    vector<int> count(d+1);
    int kind, answer;
    kind = answer = 0;
    for (int i=0; i<k; ++i)
    {
        if (count[arr[i]] == 0)
            kind++;
        count[arr[i]]++;
    }
    for (int i=k; i<N; ++i)
    {
        count[arr[i-k]]--;
        if (count[arr[i-k]] == 0)
            kind--;
        if (count[arr[i]] == 0)
            kind++;
        count[arr[i]]++;
        answer = max(kind + (count[c] == 0),answer);
    }
    for (int i=0; i<k; ++i)
    {
        count[arr[N-k+i]]--;
        if (count[arr[N-k+i]] == 0)
            kind--;
        if (count[arr[i]] == 0)
            kind++;
        count[arr[i]]++;
        answer = max(kind + (count[c] == 0),answer);
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