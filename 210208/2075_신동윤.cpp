/*
    BOJ 2075 N번째 큰 수
    https://www.acmicpc.net/problem/2075
*/

#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;

    int temp;
    for (int i = 0; i < N * N; ++i) {
        cin >> temp;
        if (pq.size() < N)
            pq.push(temp);
        else {
            int num = pq.top();
            if (num < temp) {
                pq.pop();
                pq.push(temp);
            }
        }
    }

    cout << pq.top();

    return 0;
}