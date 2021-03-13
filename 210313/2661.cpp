#include <iostream>
#include <vector>
using namespace std;

vector<int> Arr(81, 0);
int N;

bool check(vector<int> value, int length) {

	for (int size = 2; size <= (length + 1) / 2; size++) {
		bool CHECK = true;
		int frontindex = length;
		int backindex = length - size;
		for (int i = 0; i < size; i++) {
			if (value[frontindex--] != value[backindex--]) {
				CHECK = false;
				break;
			}
		}
		if (CHECK) return false; // 인접한 두 부분 수열이 동일하면
	}
	return true; // 동일한 부분 수열이 없으면
}

void dfs(int length, int num) {
	if (length == N) {
		for (int i = 0; i < N; i++) printf("%d", Arr[i]);
		exit(0);
	}

	int num1, num2;
	switch (num) {
	case 1:
		num1 = 2;
		num2 = 3;
		break;
	case 2:
		num1 = 1;
		num2 = 3;
		break;
	case 3:
		num1 = 1;
		num2 = 2;
	}

	
	Arr[length] = num1;
	if (check(Arr, length)) dfs(length + 1, num1);
	Arr[length] = 0;

	Arr[length] = num2;
	if (check(Arr, length)) dfs(length + 1, num2);
	Arr[length] = 0;

}

int main()
{
	scanf("%d", &N);
	Arr[0] = 1;

	dfs(1, 1);

	return 0;
}