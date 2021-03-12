#include <iostream>
#include <string>

using namespace std;

int N;
string str;
bool flag;  // 좋은수열을 찾은 경우

void recursion(string temp, int depth) {
    if (flag) return;

    int len = temp.size();
    for (int idx = 1; idx <= (len / 2); ++idx) {
        if (temp.substr(len - idx, idx) == temp.substr(len - (2 * idx), idx)) {  // 뒤에서 부터 확인
            temp = "";
            return;
        }
    }

    if (depth > N) return;

    if (depth == N) {
        flag = true;
        cout << temp;
        return;
    } else {
        for (int i = 0; i < N; ++i) {
            recursion(temp + "1", depth + 1);
            recursion(temp + "2", depth + 1);
            recursion(temp + "3", depth + 1);
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    recursion(str, 0);

    return 0;
}