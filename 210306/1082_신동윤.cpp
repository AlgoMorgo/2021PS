#include <algorithm>
#include <iostream>
#include <string>

#define INF 987654321

using namespace std;

int N, money;
int arr[10];
string answer; 

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	cin >> N;
	
	for (int i = 0; i < N; ++i) cin >> arr[i];
	
	cin >> money;
		
	int first = INF, second = INF; // 0 ~ N 에서 가장싼 숫자, 1 ~ N 에서 가장싼 숫자 
	int first_idx, second_idx; 
	
	for (int i = 0; i < N; ++i) {
		if (arr[i] < first) {
			first = arr[i];
			first_idx = i;
		}
	}
	
	for (int i = 1; i < N; ++i) {
		if (arr[i] < second) {
			second = arr[i];
			second_idx = i;
		}
	}
	
	if (money < second) {
		cout << "0";
		return 0;
	}
	
	money -= second;
	answer.push_back('0' + second_idx);
	while(money >= first) {
		answer.push_back('0' + first_idx);
		money -= first;
	}
	
	int idx;
	
	for (int i = 0; i < answer.length(); ++i) {
		for (int j = N - 1; j >= 0; --j) {
			idx = answer[i] - '0';
						
			if (money >= arr[j] - arr[idx]) { // 비용 뒤에서 부터 살수있으면  
				money -= (arr[j] - arr[idx]);
				answer[i] = '0' + j;
				break;
			}			
		}
	}
	
	cout << answer;
	
	return 0;
}