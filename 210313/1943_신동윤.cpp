#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int N;
pair<int, int> coin[101]; // 동전의 가치, 동전의 갯수 
bool dp[50001]; // dp[i] => i 원을 만들어 낼 수 있는가 없는가 

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	for (int tc = 0; tc < 3; ++tc) {
		int sum = 0; 
		memset(dp, false, sizeof(dp)); // 매 케이스마다 초기화필요 
		dp[0] = true; // 0 원은 당연히 true 
		
		cin >> N;
		for (int i = 0; i < N; ++i) {
			cin >> coin[i].first >> coin[i].second; 
			sum += (coin[i].first * coin[i].second);
		}
		
		if (sum % 2 == 1) { // 합이 홀수면 절반으로 분배 불가능 
			cout << "0\n";
			continue;
		}
		
		sort(coin, coin + N);
		
		for (int i = 0; i < N; ++i) {
			for (int j = sum / 2; j >= coin[i].first; --j) {
				if (dp[j - coin[i].first]) {
					for (int k = 0; k < coin[i].second; ++k) {
						if (j + k * coin[i].first > sum / 2) break;
						dp[j + k * coin[i].first] = true;
					}
				}
			}
		} 
		
		cout << dp[sum / 2] << "\n";
	}
	
	return 0;
}