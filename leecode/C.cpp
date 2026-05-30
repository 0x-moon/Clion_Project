#include <iostream>
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
typedef long long ll;typedef pair<int,int> PII;typedef priority_queue<PII,vector<PII>,greater<PII>> PQ;
const int INF=0x3f3f3f3f;const int MOD=1e9+7;const int N=2e5+10;


int n,w;
ll bucket[4*N];
void solve() {
    cin>>n>>w;
    for (int i=0;i<4*w;++i) {
        bucket[i]=0;
    }
    int T=2*w;
    for (int i=1;i<=n;++i) {
        int x;cin>>x;
        bucket[i%T]+=x;
    }
    if (n<=w) {
        cout<<0<<endl;
        return;
    }
    rep(i,0,T) {
        bucket[i+T]=bucket[i];
    }
    int sum=0;
    for (int i=0;i<w;++i) {
        sum+=bucket[i];
    }
    int ans=sum;
    for (int i=1;i<=T;++i) {
        sum = sum - bucket[i - 1] + bucket[i + w - 1];
        if (sum < ans) ans = sum;
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