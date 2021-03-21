#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int N, X;
string answer;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> X;

    if (X < N || 26 * N < X) {
        cout << "!";
        return 0;
    }

    // 초기화
    for (int i = 0; i < N; ++i) answer += 'A';
    X -= N;

    for (int i = N - 1; i >= 0 && X > 0; --i) {
        int temp = min(X, 25);
        answer[i] += temp;
        X -= temp;
    }

    cout << answer;

    return 0;
}