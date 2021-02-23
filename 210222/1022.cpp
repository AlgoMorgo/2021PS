#include <bits/stdc++.h>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;

int arr[50][5];

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	
	int x = 0, y = 0, cnt = 1, i = 1, d = 0, value = 0, c = 0, M = 0;

	if (x <= c2 && x >= c1 && y <= r2 && y >= r1) {
		arr[y - r1][x - c1] = cnt;
		M = max(M, cnt);
		c++;
	}

	if (c != ((r2 - r1 + 1) * (c2 - c1 + 1))) {
		while (true) {
			if (value == 2) {
				i++; value = 0;
			}
			for (int j = 0; j < i; j++) {
				cnt++;
				x += dx[d];
				y += dy[d];

				if (x <= c2 && x >= c1 && y <= r2 && y >= r1) {
					arr[y - r1][x - c1] = cnt;
					M = max(M, cnt);
					c++;
					if (c == ((r2 - r1 + 1) * (c2 - c1 + 1))) break;
				}
			}
			if (c == ((r2 - r1 + 1) * (c2 - c1 + 1))) break;
			d = (d + 1) % 4;
			value++;
		}
	}

	int space = 0;
	while (M != 0) {
		M /= 10;
		space++;
	}

	for (int k = 0; k <= r2 - r1; k++) {
		for (int l = 0; l <= c2 - c1; l++) {
			cout << setw(space) << arr[k][l] << ' ';
		}
		cout << '\n';
	}
	


	return 0;
}
