#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>



using namespace std;
#define js ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define int long long
#define endl '\n'
typedef pair<int,int> PII;
const int inf=0x3f3f3f3f3f3f3f3f;
const int N=1e3+10;

int n,m;
struct P {
    int a,b,c,d;
}p[N];

struct Edge {
    int to;
    int weight;
    int next;
}edge[N*N];
int idx=0, h[N];
int dist[N];

bool cmp(P &x,P &y) {
    if (x.a!=y.a)return x.a>y.a;
    return x.b>y.b;
}
void init(int n) {
    idx=0;
    for (int i=1;i<=n;++i) {
        h[i]=-1;
        dist[i]=-inf;
    }
}

void add(int a,int b,int w) {
    edge[idx].to=b;
    edge[idx].weight=w;
    edge[idx].next=h[a];
    h[a]=idx++;
}


int dij(int s) {
    priority_queue<PII> q;
    dist[s]=p[s].c;
    q.push({dist[s], s});
    while (!q.empty()) {
        auto it = q.top();
        q.pop();
        int tar=it.second, weight=it.first;
        for (int i=h[tar]; i!=-1; i=edge[i].next){
            int j=edge[i].to;
            if (dist[j]<dist[tar]+edge[i].weight) {
                dist[j]=dist[tar]+edge[i].weight;
                q.push({dist[j],j});
            }

        }
    }
    return 0;
}

void solve() {
    while(cin>>n) {
        if (n==0)break;
        init(n);
        for (int i=1;i<=n;++i) {
            cin>>p[i].a>>p[i].b>>p[i].c>>p[i].d;
            if (p[i].a>p[i].b)swap(p[i].a,p[i].b);
        }
    sort(p+1,p+n+1,cmp);
        for (int i=1;i<=n;++i) {
            for (int j=i+1;j<=n;++j) {
                if (p[i].d==0) {
                    if (p[i].a>=p[j].a&&p[i].b>=p[j].b) {
                        add(i,j,p[j].c);
                    }
                }
                else if (p[i].d==1) {
                    if (p[i].a>=p[j].a&& p[i].b>=p[j].b && (p[i].a*p[i].b>p[j].a*p[j].b)) {
                        add(i,j,p[j].c);
                    }
                }
                else if (p[i].d==2) {
                    if (p[i].a>p[j].a&& p[i].b>p[j].b) {
                        add(i,j,p[j].c);
                    }
                }
            }
        }
        int ans=-inf;
        for (int i=1;i<=n;++i) {
            if (dist[i]==-inf) {
                dij(i);
            }
            for (int j=1;j<=n;++j) {
                ans=max(dist[j],ans);
            }
        }
        cout<<ans<<endl;
    }
}

signed main() {
    js;
    int T=1;
    //cin>>T;
    while (T--) {
        solve();
    }
    return 0;
}