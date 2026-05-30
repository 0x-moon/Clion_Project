#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define js ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define endl '\n'
typedef long long ll;
typedef pair<int,int> PII;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const int N=1e5+10;

int n, k;

void solve() {
    cin >> n >> k;

    // 存储所有的“事件”
    // pair的第一个元素是坐标，第二个元素是变化值（+1 或 -1）
    vector<PII> events;

    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;

        // 区间有效起点：l - k，覆盖数 +1
        events.push_back({l - k, 1});
        // 区间有效终点之后：r + 1，覆盖数 -1
        events.push_back({r + 1, -1});
    }

    // 按照坐标从小到大排序
    // 如果坐标相同，第二个元素小的(-1)排在前面，完美避免假相交
    sort(events.begin(), events.end());

    int ans = 0;
    int current_coverage = 0;

    // 扫描线扫过所有事件
    for (auto &event : events) {
        current_coverage += event.second; // 加上当前事件的影响 (+1 或 -1)
        ans = max(ans, current_coverage); // 更新最大覆盖数
    }

    cout << ans << endl;
}

int main() {
    js;
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}