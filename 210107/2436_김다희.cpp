#include <iostream>
#include <math.h>
using namespace std;

int gcd(int a, int b) {
	if (a < b) swap(a, b);
	int n;
	while (b) {
		n = a % b;
		a = b;
		b = n;
	}
	return a;
}

int main() {

	int a, b;

	cin >> a >> b;

	int num = b / a;
	int x = sqrt(num);
	// 최소공배수 나누기 최대공약수 값을 num이라고 한다. 
	// num = B*a / a
	// 곱하면 num이 되는 두 서로소 값을 각각 최대공약수에 곱해주면 정답임.
	// 서로소가 아니라면 최대공약수 값이 바뀜
	// 합이 가장 작은 수를 구하기 위해서는 루트 num에 가장 가까운 수를 구하면 됨.
	while (true)
	{
		if (num % x == 0 && gcd(x, num / x) == 1)
		{
			cout << a * x << ' ' << a * (num / x);
			break;
		}
		x--;
	}

	return 0;

	
}
