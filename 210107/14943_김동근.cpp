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

// 벼룩 개수
long long arr[100001];
// 판매 가게 인덱스
long long sell[100001];
// 구매 가게 인덱스
long long buy[100001]; 
// 구매/판매 가게 개수
int buySize = 0, sellSize = 0; 
// 가게 총 개수
int n; 

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] > 0)  sell[sellSize++] = i;
		else buy[buySize++] = i;
	}


	int i = 0; // 전체 가게 인덱스
	int bi = 0, si = 0; // 구매 / 판매 가게 인덱스
	long long ans = 0; // 총합
	while (i < n) {
		if (arr[i] < 0) { // 구매 가게일 때
			long long& temp = arr[i]; // 구매 벼룩 개수
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
			si = j - 1; // 구매 인덱스 저장
		}
		else if (arr[i] > 0) { // 판매 가게 일때
			long long& temp = arr[i]; // 판매 벼룩 개수
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
			bi = j - 1; // 판매 인덱스 저장
		}
		i++;
	}
	cout << ans;
	return 0;
}