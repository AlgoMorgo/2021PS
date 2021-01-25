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
int n, k;
string str;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	cin >> n >> k >> str;

	stack<char> s;
	s.push(str[0]);
	int i = 1;
	while (i < n && k > 0) {
		// 현재값보다 스택에 있는 값이 작으면 스택에서 비우기
		while (!s.empty() && s.top() < str[i] && k > 0) {
			s.pop();
			k--;
		}
		s.push(str[i]);
		i++;
	}
	string temp = "";
	while (!s.empty()) {
		temp += s.top();
		s.pop();
	}

	reverse(temp.begin(), temp.end());
	// k가 남았으면 뒤에서 k개 만큼 버리기
	if (k != 0) temp = temp.substr(0, temp.size() - k);

	cout << temp << str.substr(i);

	return 0;
}