/*
    BOJ 2436 공약수
    https://www.acmicpc.net/problem/2436
*/

#include <iostream>

using namespace std;

int GCD(int a, int b) {
    int result = a % b;
    while (result != 0) {
        a = b;
        b = result;
        result = a % b;
    }
    return b;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int gcd, lcm, idx;
    cin >> gcd >> lcm;

    lcm /= gcd;
    for (int i = 1; i * i <= lcm; ++i)  // 약수 찾기 위한 반복문
        if (lcm % i == 0)               // 약수
            if (GCD(i, lcm / i) == 1)   // 서로소 일때
                idx = i;

    cout << gcd * idx << " " << gcd * (lcm / idx);

    return 0;
}

// 1. 최소공배수를 최대공약수로 나눔
// 2. 1에서 구한 숫자의 약수를 구함
// 3. 약수 중 서로소인 것만 추려냄
// 4. 추려낸 값에 최대 공약수를 구하면 정답후보군이 됨
// 5. 그 중 가장 작은 값을 찾아냄