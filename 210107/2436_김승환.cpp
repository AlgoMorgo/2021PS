/**
 * 2436 공약수
 * gcd와 관련된 성질 문제
 */

#include <iostream>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

void solve()
{
    int g, l;
    cin >> g >> l;

    long long i, k = (long long)g*l;
    for (i=1; i*i<k; ++i);
    for (; i>0; --i)
    {
        if (k%i == 0 && gcd(i, k/i) == g)
            break;
    }

    cout << i << ' ' << k/i;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}