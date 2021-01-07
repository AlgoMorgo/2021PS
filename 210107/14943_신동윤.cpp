/*
    BOJ 14943 벼룩 시장
    https://www.acmicpc.net/problem/14943
*/

#include <cmath>
#include <iostream>

#define MAX 100001

using namespace std;

int N, L;
int arr[MAX];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; ++i) cin >> arr[i];

    long long answer = 0, temp = 0;
    for (int i = 0; i < N; ++i) {
        temp += arr[i];
        answer += abs(temp);
    }

    cout << answer;

    return 0;
}