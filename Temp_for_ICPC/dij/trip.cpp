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
const int inf=0x3f3f3f3f;const int MOD=1e9+7;
const int N=1e5+10;


int n,m,k;

struct Edge {
    int to;
    int weight;
    int next;
}edge1[N*2];
int idx=1,h1[N];
int a[N]={0};
int dist[N];

void init(int h[],int dist[],int n) {
    idx=0;
    for (int i=1;i<=n;++i) {
        h[i]=-1;
        dist[i]=inf;
    }
}
void add(int a,int b,int w=0) {
    edge[idx].to=b;edge[idx].weight=w;edge[idx].next=h[a];
    h[a]=idx++;
}
int dij(int lim) {
    priority_queue<PII,vector<PII>,greater<PII>> q;
    dist[1]=0;
    if (a[1]>lim)return inf;
    q.push({0,1});
    while (!q.empty()) {
        auto it = q.top();
        q.pop();
        int tar=it.second,weight=it.first;
        for (int i=h[tar];i!=-1;i=edge[i].next){
            int j=edge[i].to;
            if (edge[i].weight+weight<dist[j]&&(a[j]<=lim||j==n)) {
                dist[j]=edge[i].weight+weight;
                q.push({dist[j],j});
            }
        }
    }
    return dist[n];
}
void solve() {
    cin>>n>>m>>k;
    init(h,dist,n);
    for (int i=1;i<=n;++i) cin>>a[i];

    for (int i=0;i<m;++i) {
        int a,b,w;
        cin>>a>>b>>w;
        add(a,b,w);
        add(b,a,w);
    }
    int l=1,r=1e9+10,ans=inf;
    while (l<r) {
        for(int i=1;i<=n;++i) dist[i]=inf;
        int mid=l+r>>1;
        int ret=dij(mid);
        if (ret<=k&&ret!=inf) {
            r=mid;
            ans=r;
        }else {
            l=mid+1;
        }
    }
    if (ans==inf)cout<<-1<<endl;
    else cout<<ans<<endl;



}

signed main() {
    js;
    int T=1;
    //cin>>T;
    while (T--) {solve();}
    return 0;
}

