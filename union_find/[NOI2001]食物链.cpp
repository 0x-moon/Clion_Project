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
const int INF=0x3f3f3f3f;const int mod=1e9+7;const int N=5e4+10;



int op,x,y;
int p[3*N];//拓展域并查集
int find(int x) {
    if (p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
void _union(int x,int y) {
    p[find(x)]=find(y);
}

void solve() {
    int ans=0;
    int n,k;cin>>n>>k;
    for (int i=1;i<=3*n;++i) p[i]=i;
    while (k--) {
        cin>>op>>x>>y;
        if (x>n||y>n) {
            ans++;
            continue;
        }
        if (op == 2 && x == y) {
            ans++;
            continue;
        }
        if (op==1) {
            if (find(x+n)==find(y)||find(y+n)==find(x)) {
                ans++;
            }else {
                _union(x,y);
                _union(x+n,y+n);
                _union(x+2*n,y+2*n);
            }
        }else {
            if (find(y+n)==find(x)||find(x)==find(y)) {
                ans++;
            }else {
                _union(y,x+n);
                _union(y + n, x + 2 * n);
                _union(y+ 2 * n,x );
            }

        }
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


