#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

// 判定：a个(q+1)和b个q能否凑出T
bool can_reach(ll rA, ll rB, ll T, ll q) {
    if (T < 0) return false;
    if (q == 0) return T <= rA;

    // k = a + b, a = T - qk
    ll min_k1 = (T - rA <= 0) ? 0 : (T - rA + q - 1) / q;
    ll max_k1 = T / q;
    ll min_k2 = (T + (q + 1) - 1) / (q + 1);
    if (T == 0) min_k2 = 0;
    ll max_k2 = (T + rB) / (q + 1);

    return max(min_k1, min_k2) <= min(max_k1, max_k2);
}

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;
    string s; cin >> s;

    ll L = x + y;
    ll q = L / n, r = L % n;

    ll cur_y = 0, rA = 0, rB = 0;
    for (int i = 0; i < n; ++i) {
        ll W = (i < r ? q + 1 : q);
        if (s[i] == '1') cur_y += W;
        else if (s[i] == '2') (i < r ? rA++ : rB++);
    }

    ll target_v = y - cur_y;
    if (!can_reach(rA, rB, target_v, q)) {
        cout << -1 << endl; return;
    }

    // 正向贪心：能选 0 尽量选 0
    for (int i = 0; i < n; ++i) {
        if (s[i] == '2') {
            ll W = (i < r ? q + 1 : q);
            if (i < r) rA--; else rB--;

            // 尝试填 0
            if (can_reach(rA, rB, target_v, q)) {
                s[i] = '0';
            } else {
                s[i] = '1';
                target_v -= W;
            }
        }
    }
    cout << s << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}