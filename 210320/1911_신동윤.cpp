#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, L, answer;
vector<pair<int, int>> pools;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> L;
    for (int i = 0; i < N; ++i) {
        int start, end;
        cin >> start >> end;
        pools.push_back({start, end});
    }

    sort(pools.begin(), pools.end());

    int next = 0;
    for (int i = 0; i < pools.size(); ++i) {
        if (next < pools[i].first) next = pools[i].first;

        while (next < pools[i].second) {
            next += L;
            answer++;
        }
    }

    cout << answer;

    return 0;
}