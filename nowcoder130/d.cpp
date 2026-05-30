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
typedef long long ll;typedef pair<int,int> PII;typedef priority_queue<int,vector<int>,greater<int>> pqIG;
const int INF=0x3f3f3f3f;const int mod=1e9+7;const int N=2e5+10;


ll qpow(int a,int b,int mod) {
    ll ans=1;
    while (b) {
        if (b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int gcd(int a,int b) {
    return b==0?a:gcd(b,a%b);
}
void solve() {
    ll a,b;
    cin>>a>>b;
    for (int i=2;i<1000;++i) {
        ll t=qpow(10, a-1,i);
        for (int j=1;j<i;++j) {
            if (gcd(i,j)!=1)continue;
            if ((j*t*10/i)%10==b) {
                cout<<j<< ' '<<i<<endl;
                return ;
            }
        }
    }
}

int main() {
    js;
    int T=1;
    cin>>T;
    while (T--) {solve();}
    return 0;
}

