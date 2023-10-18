#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;
int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> z;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            z.push_back(i);
        }
    }

    int sz = z.size();
    if (sz == 0 || sz == 1) {
        cout << 0 << endl;
        return 0;
    }

    if (sz % 2 == 0) {
        int ans = 0;
        for (int i = 0; i <= sz - 2; i += 2) {
            ans += z[i + 1] - z[i];
        }
        cout << ans << endl;
    } else {
        int ans = -1;
        for (int i = 0; i < sz; i++) {
            int ans_tmp = 0;
            for (int j = 0; j <= sz - 2; j++) {
                if (i == j) continue;
                ans_tmp += z[i + 1] - z[i];
            }
            if (ans == -1) {
                ans = ans_tmp;
            } else {
                ans = min(ans, ans_tmp);
            }
        }
        cout << ans << endl;
    }

    return 0;
}