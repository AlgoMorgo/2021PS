/*
    BOJ 1461 도서관
    https://www.acmicpc.net/problem/1461
*/

#include <algorithm>
#include <cmath>
#include <iostream>

#define MAX 10001

using namespace std;

int n, m, answer;
int arr[MAX];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> arr[i];

    sort(arr, arr + n + 1);  // arr + n + 1 인 것은 0을 포함하기 위함임.

    int idx;
    for (int i = 0; i <= n; ++i) {
        if (arr[i] == 0) {
            idx = i;
            break;
        }
    }

    // 음수
    for (int i = 0; i < idx; i += m) answer += abs(arr[i] * 2);
    // 양수
    for (int i = n; i > idx; i -= m) answer += arr[i] * 2;

    answer -= max(abs(arr[0]), arr[n]);
    cout << answer;

    return 0;
}