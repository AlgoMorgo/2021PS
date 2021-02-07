#include <bits/stdc++.h>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	string x;
	cin >> x;
	
	stack<string> s;
	for (int i = 0; i < x.length(); i++) {
		if (x[i] == '(') s.push(string(1, x[i]));
		else if (x[i] == ')') {
			while (!s.empty() && s.top() != "(") {
				cout << s.top();  s.pop();
			}
			s.pop();
		}
		else if (x[i] == '*' || x[i] == '/') {
			while (!s.empty() && (s.top() == "*" || s.top() == "/")) {
				cout << s.top(); s.pop();
			}
			s.push(string(1, x[i]));
		}
		else if (x[i] == '+' || x[i] == '-') {
			while (!s.empty() && s.top() != "(") {
				cout << s.top(); s.pop();
			}
			s.push(string(1, x[i]));
		}
		else cout << x[i];
	}

	while (!s.empty()) {
		cout << s.top(); s.pop();
	}

	return 0;
}

