/*
    BOJ 17522 Canal
    https://www.acmicpc.net/problem/17522
*/

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

#define MAX 300005

using namespace std;

typedef long long ll;

int n;
pair<ll, ll> houses[MAX];
ll prefix_max[MAX], prefix_min[MAX];
ll suffix_max[MAX], suffix_min[MAX];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cout << setprecision(1) << fixed;

    cin >> n;
    if (n == 1) {
        cout << 0.0 << "\n";
        return 0;
    }

    for (int i = 1; i <= n; ++i)
        cin >> houses[i].first >> houses[i].second;

    sort(houses + 1, houses + n + 1);

    prefix_min[0] = suffix_min[n + 1] = (1E9) + 1;
    prefix_max[0] = suffix_max[n + 1] = -(1E9) - 1;

    for (int i = 1; i <= n; ++i) {
        prefix_min[i] = min(prefix_min[i - 1], houses[i].second);
        prefix_max[i] = max(prefix_max[i - 1], houses[i].second);
    }

    for (int i = n; i; --i) {
        suffix_min[i] = min(suffix_min[i + 1], houses[i].second);
        suffix_max[i] = max(suffix_max[i + 1], houses[i].second);
    }

    ll low = 0, high = ((ll)2E9) + 1;
    while (low + 1 < high) {
        ll mid = (low + high) / 2;
        int start = 1, end = 1;
        bool flag = false;
        while (end <= n) {
            while (start < end && houses[end].first - houses[start].first >= mid)
                start++;
            ll m = (1E9) + 1, M = -(1E9) - 1;
            if (start > 1) {
                m = min(m, prefix_min[start - 1]);
                M = max(M, prefix_max[start - 1]);
            }
            if (end < n) {
                m = min(m, suffix_min[end + 1]);
                M = max(M, suffix_max[end + 1]);
            }
            if (M - m < mid) {
                flag = true;
                break;
            }
            end++;
        }
        if (flag)
            high = mid;
        else
            low = mid;
    }

    cout << low * 0.5 << "\n";

    return 0;
}