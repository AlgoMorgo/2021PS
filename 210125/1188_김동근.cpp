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

int n, m;

int gcd(int x, int y) {
	while (y != 0) {
		int temp = y;
		y = x % y;
		x = temp;
	}
	return x;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> n >> m;

	cout << m - gcd(n, m);

	return 0;
}