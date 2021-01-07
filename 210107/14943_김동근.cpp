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

// ���� ����
long long arr[100001];
// �Ǹ� ���� �ε���
long long sell[100001];
// ���� ���� �ε���
long long buy[100001]; 
// ����/�Ǹ� ���� ����
int buySize = 0, sellSize = 0; 
// ���� �� ����
int n; 

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] > 0)  sell[sellSize++] = i;
		else buy[buySize++] = i;
	}


	int i = 0; // ��ü ���� �ε���
	int bi = 0, si = 0; // ���� / �Ǹ� ���� �ε���
	long long ans = 0; // ����
	while (i < n) {
		if (arr[i] < 0) { // ���� ������ ��
			long long& temp = arr[i]; // ���� ���� ����
			int j = si;
			while (j < sellSize && temp < 0) { 
				if (-temp <= arr[sell[j]]) { // ex) -400 500
					arr[sell[j]] += temp;
					ans += (sell[j] - i) * -temp;
					temp = 0;
				}
				else { // ex) -400 50
					temp += arr[sell[j]];
					ans += (sell[j] - i) * arr[sell[j]];
					arr[sell[j]] = 0;
				}
				j++;
			}
			si = j - 1; // ���� �ε��� ����
		}
		else if (arr[i] > 0) { // �Ǹ� ���� �϶�
			long long& temp = arr[i]; // �Ǹ� ���� ����
			int j = bi;
			while (j < buySize && temp > 0) { 
				if (temp <= -arr[buy[j]]) {// ex) 400 -500
					arr[buy[j]] += temp;
					ans += (buy[j] - i) * temp;
					temp = 0;
				}
				else { // ex) 400 -50
					temp += arr[buy[j]];
					ans += (buy[j] - i) * -arr[buy[j]];
					arr[buy[j]] = 0;
				}
				j++;
			}
			bi = j - 1; // �Ǹ� �ε��� ����
		}
		i++;
	}
	cout << ans;
	return 0;
}