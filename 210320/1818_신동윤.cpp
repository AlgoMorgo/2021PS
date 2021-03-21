#include <iostream>

#define MAX 200001

using namespace std;

int N;
int arr[MAX], lis[MAX];

int bs(int left, int right, int target) {
    int mid;

    while (left < right) {
        mid = (left + right) / 2;

        if (lis[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }

    return right;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; ++i) cin >> arr[i];

    int j = 0, i = 1;  // j 는 lis 의 인덱스, i 는 arr 의 인덱스
    lis[0] = arr[0];

    while (i < N) {
        if (lis[j] < arr[i]) {
            lis[j + 1] = arr[i];
            j++;
        } else {
            int idx = bs(0, j, arr[i]);
            lis[idx] = arr[i];
        }
        i++;
    }

    cout << N - (j + 1);

    return 0;
}