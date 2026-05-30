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
const int inf=0x3f3f3f3f;const int mod=1e9+7;
const int N=1e7+10;
#define int long long

int n,q;
int a[N];
int dp[N];
int getSSM(int n,int a[],int dp[]) {
    int ans=-inf;
    dp[0]=0;
    for (int i=1;i<=n;++i) {
        dp[i]=max(dp[i-1]+a[i],a[i]);
        ans=max(dp[i]+a[i],a[i]);
    }

    dp[0]=-inf;
    for (int i=1;i<=n;++i) {
        dp[i]=max(dp[i],dp[i-1]);
    }

    return ans;
}
void solve() {
    scanf("%lld",&n);
    for (int i=1;i<=n;++i) {
        scanf("%lld",&a[i]);
    }

    getSSM(n,a,dp);


    int ans=-inf;
    for (int i=1;i<=n;++i) {
        ans=max(dp[i],ans);
    }

    printf("%lld",ans);
}

signed main() {
    //js;
    int T=1;
    //cin>>T;
    while (T--) {solve();}
    return 0;
}
