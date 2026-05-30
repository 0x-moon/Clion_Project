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
#define forn(i,n) for(int i=0;i<(n);++i)
#define all(x) (x).begin(), (x).end()
#define js ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define endl '\n'
typedef long long ll;typedef pair<int,int> PII;typedef priority_queue<int,vector<int>,greater<int>> pq;
//const int inf=0x3f3f3f3f;
//const int MOD=1e9+7;
const ll inf=0x3f3f3f3f3f3f3f3fLL;
const int N=1e5+10;
#define int ll
int n,q,k;
int a[N];
int dppre[N],dppost[N];
//dppre[i]是子段和
int getSSM(int n,int a[],int dp[]) {
    //dp[i]代表从0开始，以i为终点的最大子段和
    //对于dp[i]有两种结果，dp[i]后面还有一个很大的ai，所以dpi并不是整个区间1-n最大的数
    //dpi本来就很小，被ai替换
    //dpi就是以某一点为起点，这一起点我不知道，然后到i的最大子段和
    int ans=-inf;
    dp[0]=0;
    for (int i=1;i<=n;++i) {
        dp[i]=max(dp[i-1]+a[i],a[i]);
        ans=max(dp[i],ans);
    }
    dp[0]=-inf;
    for (int i=1;i<=n;++i) {
        dp[i]=max(dp[i-1],dp[i]);
    }
    return ans;
}
void swap_arr(int n,int a[]) {
    for (int i=1;i<=n/2;++i) {
        swap(a[i],a[n-i+1]);
    }
}
void solve() {
    cin>>n>>k;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
    }
    getSSM(n,a,dppre);
    swap_arr(n,a);

    getSSM(n,a,dppost);
    swap_arr(n,dppost);

    int ans=-inf;
    for (int i=1;i+k+1<=n;++i) {
        ans=max(ans,dppre[i]+dppost[i+k+1]);
    }
    cout<<ans<<endl;
}

signed main() {
    js;
    int T=1;
    //cin>>T;
    while (T--) {solve();}
    return 0;
}

