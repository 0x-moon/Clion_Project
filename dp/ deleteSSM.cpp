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
const int inf=-0x3f3f3f3f;const int MOD=1e9+7;
const int N=1e5+10;
const int K=101;


int n,k;
int a[N];
int dp[N][K];//dp[i][j]代表前i个子数组删除j个元素后的最大子段和

void solve() {
    cin>>n>>k;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
    }
    dp[0][0]=0;
    for(int j=1;j<=k;++j){
        dp[0][j]=inf;
    }
    for(int i=1;i<=n;++i){
        dp[i][0]=a[i]+max(dp[i-1][0],0);
        for(int j=1;j<=k;++j){
            dp[i][j]=max(dp[i-1][j]+a[i],dp[i-1][j-1]);
        }        
    }
    int max_ans=inf;
    for(int i=1;i<=n;++i){
        for(int j=0;j<=k;++j){
            max_ans=max(dp[i][j],max_ans);
        }        
    }
    cout<<max_ans<<endl;
   
}

int main() {
    js;
    int T=1;
    //cin>>T;
    while (T--) {solve();}
    return 0;
}

