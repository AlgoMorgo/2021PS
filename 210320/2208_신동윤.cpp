#include <algorithm>
#include <iostream>

using namespace std;

int N, M, answer;
int prefix[100001];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        prefix[i + 1] = prefix[i] + num;
    }

    int previous = 0;
    for (int i = M - 1; i < N; ++i) {
        previous = min(previous, prefix[i - M + 1]);
        answer = max(answer, prefix[i + 1] - previous);
    }

    cout << answer;

    return 0;
}