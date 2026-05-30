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
const int INF=0x3f3f3f3f;const int MOD=1e9+7;
const int N=1e5+10;


int n,m;

struct Edge {
    int to;
    int weight;
    int next;
}edge[N*2];
int idx=0,h1[N];
int a[N]={0};
void init(int h[],int n) {
    idx=0;
    for (int i=1;i<=n;++i) {
        h[i]=-1;
    }
}
void add(int a,int b,int w=0) {
    edge[idx].to=b;edge[idx].weight=w;edge[idx].next=h[a];h[a]=idx++;
}
void dfs(int u,int maxd) {
    if (a[u]!=0)return;
    a[u]=maxd;
    for (int i=h[u];i!=-1;i=edge[i].next) {
        dfs(edge[i].to,maxd);
    }
}



void solve() {
    cin>>n>>m;

    init(h,n);

    for (int i=0;i<m;++i) {
        int a,b,w;
        cin>>a>>b;
        add(b,a,w);
        //add(b,a,w);
    }

    for (int i=n;i>=1;--i) {
        dfs(i,i);
    }
    for (int i=1;i<=n;++i) {
        cout<<a[i]<<' ';
    }
    cout<<endl;




}

int main() {
    js;
    int T=1;
    //cin>>T;
    while (T--) {solve();}
    return 0;
}

