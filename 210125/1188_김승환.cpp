#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a%b) : a;
}

void solve()
{
    int N, M;
    cin >> N >> M;
    cout << M - gcd(N, M);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}