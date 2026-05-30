#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <utility>
#include <vector>
#include <deque>
#include <queue>
#include <unordered_map>

using namespace std;
#define all(x) (x).begin(), (x).end()
#define js ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define endl '\n'
typedef long long ll;typedef pair<int,int> PII;typedef priority_queue<int,vector<int>,greater<int>> pq;
const int inf=0x3f3f3f3f;const int mod=1e9+7;
const int N=1e6+10;


int n,m;
int a[N];
int dp[N];
int pre_max[N];


int getSSM(int n,int a[],int dp[],int i) {
    int cur_max_ans = -inf;

    for (int j = i; j <= n; ++j) {
        // 核心逻辑：
        // dp[j-1] + a[j] 是续接在当前第 i 段
        // pre_max[j-1] + a[j] 是新开一段（接在之前的 i-1 段后面）
        dp[j] = max(dp[j - 1], pre_max[j - 1]) + a[j];
        pre_max[j - 1] = cur_max_ans;
        cur_max_ans = max(cur_max_ans, dp[j]);
    }
    // 最后一个位置的更新
    pre_max[n] = cur_max_ans;
    return cur_max_ans;
}

void solve() {
    while (scanf("%d %d", &m, &n) != EOF) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            dp[i] = 0;
            pre_max[i] = 0;
        }

        int ans = -inf;

        for (int i = 1; i <= m; ++i) {
            ans = getSSM(n,a,dp,i);
        }

        printf("%d\n", ans);
    }
}
signed main() {
    //js;
    int T=1;
    //cin>>T;
    while (T--) {solve();}
    return 0;
}
