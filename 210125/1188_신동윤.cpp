/*
    BOJ 1188 음식 평론가
    https://www.acmicpc.net/problem/1188
*/

#include <iostream>

using namespace std;

int n, m;

int gcd(int a, int b) { return a % b == 0 ? b : gcd(b, a % b); }

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    cout << m - gcd(m, n);

    return 0;
}