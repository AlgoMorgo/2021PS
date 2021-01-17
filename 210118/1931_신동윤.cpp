/*
    BOJ 1931 회의실 배정
    https://www.acmicpc.net/problem/1931
*/

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int N, minimum, cnt;
vector<pair<int, int>> vec;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        vec.push_back(make_pair(x, y));
    }

    sort(vec.begin(), vec.end());
    sort(vec.begin(), vec.end(), compare);

    minimum = vec[0].second;
    cnt++;

    for (int i = 1; i < N; i++) {
        if (vec[i].first >= minimum) {
            minimum = vec[i].second;
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}
