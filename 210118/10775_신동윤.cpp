/*
    BOJ 10775 공항
    https://www.acmicpc.net/problem/10775
*/

#include <iostream>

#define MAX 100001

using namespace std;

int G, P, answer;
int arr[MAX];

int _find(int n) {
    if (arr[n] == n) return n;
    arr[n] = _find(arr[n]);
    return arr[n];
}

void _union(int a, int b) {
    a = _find(a);
    b = _find(b);
    arr[a] = b;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> G;
    cin >> P;

    for (int i = 1; i <= G; ++i) arr[i] = i;

    for (int i = 1; i <= P; ++i) {
        int g;
        cin >> g;

        int temp = _find(g);
        if (temp != 0) {
            _union(temp, temp - 1);
            answer++;
        } else
            break;
    }

    cout << answer;

    return 0;
}