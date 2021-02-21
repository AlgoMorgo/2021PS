#include <bits/stdc++.h>

using namespace std;

string str;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> str;

    int p_cnt = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == 'P') {
            p_cnt++;
            continue;
        }

        if (p_cnt >= 2 && str[i + 1] == 'P') {  // 현재 'A'
            p_cnt--;                            // PPAP 를 P 로 치환했으므로 하나 감소
            i++;
        } else {
            cout << "NP";
            return 0;
        }
    }

    if (p_cnt == 1)
        cout << "PPAP";  // 마지막에 P 가 하나 있을때 PPAP
    else
        cout << "NP";

    return 0;
}
