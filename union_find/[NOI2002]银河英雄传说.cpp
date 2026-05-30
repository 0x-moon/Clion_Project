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
const int INF=0x3f3f3f3f;const int mod=1e9+7;const int N=3e4+10;


string op;
int p[N],s[N];
int d[N];
int find(int x) {
    if (p[x]!=x){int t=find(p[x]); d[x]+=d[p[x]]; p[x]=t;} return p[x];}
void _union(int x,int y) {
    int rx=find(x),ry=find(y);
    if (rx!=ry) {p[rx]=ry; d[rx]=s[ry]; s[ry]+=s[rx];}}

void solve() {
    int q; cin>>q;
    for (int i=1;i<=30000;++i) {
        p[i]=i;
        d[i]=0;
        s[i]=1;
    }
    while (q--) {
        cin>>op;
        int x,y;
        if (op[0]=='M') {
            cin>>x>>y;
            _union(x,y);
        }else {
            cin>>x>>y;
            if (find(x)==find(y)) {
                cout<<abs(d[x]-d[y]+1)<<endl;
            }else {
                cout<<-1<<endl;
            }

        }
    }


}

int main() {
    js;
    int T=1;
    //cin>>T;
    while (T--) {solve();}
    return 0;
}


