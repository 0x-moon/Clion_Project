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
const int inf=0x3f3f3f3f;const int mod=1e9+7;
const int N=1e6+10;


int n,m,k;
struct Edge {
    int to;
    int weight;
    int next;
}edge1[N*2],edge2[N*2];
int idx1=1,idx2=0,h[N],h2[N];
int a[N]={0};
int dist[N];

void init(int h1[],int h2[],int dist[],int n) {
    idx1=0,idx2=0;
    for (int i=1;i<=n;++i) {
        h1[i]=-1;
        h2[i]=-1;
        dist[i]=inf;
    }
}
void add1(int a,int b,int w=0) {
    edge[idx1].to=b;edge[idx1].weight=w;edge[idx1].next=h[a];
    h[a]=idx1++;
}
void add2(int a,int b,int w=0) {
    edge2[idx2].to=b;edge2[idx2].weight=w;edge2[idx2].next=h2[a];
    h2[a]=idx2++;
}
ll dij(int h[],Edge edge[]) {
    ll ans=0;
    priority_queue<PII,vector<PII>,greater<PII>> q;
    dist[1]=0;
    q.push({0,1});
    while (!q.empty()) {
        auto it = q.top();
        q.pop();
        int tar=it.second,weight=it.first;
        for (int i=h[tar];i!=-1;i=edge[i].next){
            int j=edge[i].to;
            if (edge[i].weight+weight<dist[j]) {
                dist[j]=edge[i].weight+weight;
                q.push({dist[j],j});
            }
        }
    }
    for (int i=1;i<=n;++i) {
        ans+=dist[i];
    }
    return  ans;
}
void solve() {
    cin>>n>>m;
    init(h,h2,dist,n);
    ll ans=0;
    for (int i=0;i<m;++i) {
        int a,b,w;
        cin>>a>>b>>w;
        add1(a,b,w);
        add2(b,a,w);
    }
    ans+=dij(h,edge);
    for (int i=1;i<=n;++i) {
        dist[i]=inf;
    }
    ans+=dij(h2,edge2);
    cout<<ans<<endl;
}

signed main() {
    js;
    int T=1;
    cin>>T;
    while (T--) {solve();}
    return 0;
}

