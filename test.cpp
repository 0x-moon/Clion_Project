#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define js ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define endl '\n'
typedef long long ll;typedef pair<int,int> PII;
const int inf=0x3f3f3f3f;const int mod=1e9+7;
const int N=2e5+10;


int n;
int a[N];
int b[N];
int dp[N];
void solve() {
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
    }
    b[1]=a[1];
    for (int i=2;i<=n;++i) {
       b[i]=b[i-1]+a[i];
    }
    dp[1]=0;
    int ans=-1;
    int idx=-1;
    for (int i=2;i<=n;++i) {
        dp[i]=b[i-1]-(a[i]*(i-1));
        if (dp[i]<0)dp[i]=0;
        if (ans<dp[i]) {
            idx=i;
            ans=dp[i];
        }
    }
    if (idx!=-1) {
        for (int i=idx;i<=n;++i) {
            dp[i]=b[i-1]-(a[i]*(i-1));
            if (dp[i]<0)dp[i]=0;
            ans=max(ans,dp[i]);
        }
    }
     idx=-1;
    for (int i=2;i<=n;++i) {
        dp[i]=b[i-1]-((a[i]-1)*(i-1));
        if (dp[i]<0)dp[i]=0;
        if (ans<dp[i]) {
            idx=i;
            ans=dp[i];
        }
    }
    if (idx!=-1) {
        for (int i=idx;i<=n;++i) {
            dp[i]=b[i-1]-((a[i]-1)*(i-1));
            if (dp[i]<0)dp[i]=0;
            ans=max(ans,dp[i]);
        }
    }
    cout<<ans<<endl;


}

int main() {
    js;
    int T=1;
    cin>>T;
    while (T--) {solve();}
    return 0;
}

