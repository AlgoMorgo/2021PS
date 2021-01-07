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
	// �ּҰ���� ������ �ִ����� ���� num�̶�� �Ѵ�. 
	// num = B*a / a
	// ���ϸ� num�� �Ǵ� �� ���μ� ���� ���� �ִ������� �����ָ� ������.
	// ���μҰ� �ƴ϶�� �ִ����� ���� �ٲ�
	// ���� ���� ���� ���� ���ϱ� ���ؼ��� ��Ʈ num�� ���� ����� ���� ���ϸ� ��.
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
