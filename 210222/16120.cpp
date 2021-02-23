#include <bits/stdc++.h>
using namespace std;

string str;
vector<char> v;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> str;
	v.push_back(str[0]);
	for (int i = 1; i <= str.size(); i++) {
		while (v.size() >= 4) {
			char a = v.back(); v.pop_back();
			char b = v.back(); v.pop_back();
			char c = v.back(); v.pop_back();
			char d = v.back(); v.pop_back();

			if (d == 'P' && c == 'P' && b == 'A' && a == 'P') {
				v.push_back('P');
			}
			else {
				v.push_back(d); v.push_back(c); v.push_back(b); v.push_back(a);
				break;
			}
		}
		if (i == str.size()) break;
		v.push_back(str[i]);
	}

	if (v.size() == 1 && v[0] == 'P') cout << "PPAP";
	else cout << "NP";

	return 0;
}
