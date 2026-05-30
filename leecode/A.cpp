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
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define all(x) (x).begin(), (x).end()
#define js ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
typedef long long ll;typedef pair<int,int> PII;typedef priority_queue<int> pq;
const int INF=0x3f3f3f3f;const int MOD=1e9+7;const int N=2e5+10;


int x,y;
ll qpow(ll a,ll b,ll mod) {
    ll ans=1;
    a%=mod;
    while (b) {
        if (b&1) {
            ans=(ans*a)%mod;
        }
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}

void solve() {
    cin>>x>>y;
    int ans=qpow(2,y,MOD);
    cout<<x*ans<<endl;


}

int main() {
    js;
    int T=1;
    //cin>>T;
    while (T--) {solve();}
    return 0;
}

