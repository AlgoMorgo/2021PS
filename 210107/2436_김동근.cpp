#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <cmath>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;

int a, b; // 최대공약수, 최소공배수

bool gcd(int a, int b, int c) { // 최대공약수
	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return c == a;

}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	cin >> a >> b;
	int temp = b / a; // b/a = A*B  A,B 찾고자하는 자연수 쌍
	
	pair<int, int >ans;
	int sum = INT32_MAX;
	for (int i = 1; i <= (int)sqrt(temp); i++) {
		if (temp % i == 0) {
			// 실제 최대공약수를 구한값과 원래 최대공약수가 같은지 판단
			if (sum > a * (i + temp / i) && gcd(a * i, a * temp/i, a)) { 
				sum = a* (i + temp / i);
				ans.first = a * i;
				ans.second = a * temp / i;
			}
		}
	}

	cout << ans.first << ' ' << ans.second;

	return 0;
}