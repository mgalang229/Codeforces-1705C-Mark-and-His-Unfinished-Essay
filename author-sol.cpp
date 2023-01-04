#include <bits/stdc++.h>
using namespace std;

/*

mark
0 1 2 3 | 4 5 6 7 | 8 9 10 | 11 12 13 14 15 16
m a r k | m a r k | m a  r | r  k  m  a  r  k

1 = m
10 = a
12 = r

14 = m

0, 4 = x
4, 8 = 4
8, 11 = 4
11, 17 = 9

----------------------------------------

creamii
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18
c r e a m i i r e e  a  r  e  a  m  i  i  r  e

9 = e
11 = a
12 = r

0, 7 = x
7, 9 = 6
9, 11 = 7

variation:
creamii
creamiireeaeea

12 = e


*/

void test_case() {
    int n, c, q;
    cin >> n >> c >> q;
    string s;
    cin >> s;
    long long left[c+1], right[c+1], diff[c+1];
    left[0] = 0;
    right[0] = n;
    for (int i = 1; i < c + 1; i++) {
        long long l, r;
        cin >> l >> r;
        --l; --r;
        left[i] = right[i-1];
        right[i] = left[i] + (r - l + 1);
        diff[i] = left[i] - l;
    }
    // for (int i = 0; i < c + 1; i++) {
    //     cout << left[i] << " to " << right[i] << " = " << diff[i] << "\n";
    // }
    while (q--) {
        long long k;
        cin >> k;
        --k;
        for (int i = c; i > 0; i--) {
            if (k < left[i]) {
                continue;
            }
            k -= diff[i];
        }
        cout << s[k] << "\n";
    }
    // cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        test_case();
    }
}
