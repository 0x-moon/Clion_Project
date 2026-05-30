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
//https://ac.nowcoder.com/acm/problem/17511

using namespace std;
//priority_queue<PII,vector<PII>,greater<PII>> q;
#define forn(i,n) for(int i=0;i<n;++i)
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define js ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
typedef long long ll;typedef pair<int,int> PII;
const int inf=0x3f3f3f3f;const int MOD=1e9+7;const int N=1e5+10,M=N*2;


int n,m,s,t;
int e[M],ne[M],h[N],wt[M],idx=0;
int dist[N],st[N]={false};

void addedge(int u,int v,int w) {
    e[idx]=v,ne[idx]=h[u],wt[idx]=w,h[u]=idx++;
}
int dijkstra() {
    for (int i = 1; i <= n; ++i) dist[i]=inf;
    dist[s]=0;
    priority_queue<PII,vector<PII>,greater<PII> > q;
    q.push({0,s});
    while (!q.empty()) {
        auto it = q.top();
        q.pop();
        int tar=it.second,dis=it.first;
        if (st[tar])continue;
        st[tar]=1;
        for (int i=h[tar];i!=-1;i=ne[i]) {
            int j=e[i];
            if (dis+wt[i]<dist[j]) {
                dist[j]=dis+wt[i];
                q.push({dist[j],j});
            }
        }
    }
    if (dist[t]==inf)return -1;
    return dist[t];
}
void solve() {
    cin>>n>>m>>s>>t;
    forn(i,n)h[i]=-1;
    forn(i,m) {
        int u,v,w;
        cin>>u>>v>>w;
        addedge(u,v,w);
        addedge(v,u,w);
    }
        cout<<dijkstra()<<endl;



}

int main() {
    js;
    int T=1;
    //cin>>T;
    while (T--) {solve();}
    return 0;
}

