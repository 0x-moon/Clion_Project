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
const int INF=0x3f3f3f3f;const int mod=1e9+7;const int N=1e5+10;



int n;
int d[N],idx=0;

void solve() {
    cin>>n;
    for (int i=0;i<n-1;++i) {
        int a,b;
        cin>>a>>b;
        d[a]++,d[b]++;
    }
    int ans=0;
    for (int i=1;i<=n;++i) {
        if (d[i]>3) {
            ans=0;
            break;
        }
        if (d[i]<=2)ans++;
    }
    cout<<ans<<endl;

}

int main() {
    js;
    int T=1;
    //cin>>T;
    while (T--) {solve();}
    return 0;
}

