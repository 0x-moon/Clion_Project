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
int a[N];
struct Edge {
    int to;
    int weight;
    int next;
}edge1[N*2];
int idx=0,h[N];
int color[N],cnt=0;
void init(int h[],int color[],int n) {
    for (int i=1;i<=n;++i) {
        h[i]=-1;
        color[i]=-1;
    }
}
void add(int a,int b,int w=1) {//用idx表示边节点编号
    edge1[idx].to=b;edge1[idx].weight=w;edge1[idx].next=h[a];h[a]=idx++;
}
void dfs(int u) {
    if (color[u]!=-1) {
        return;
    }
    color[u]=cnt;
    for (int i=h[u];i!=-1;i=edge1[i].next) {
        //color[edge[i].to]=cnt;
        dfs(edge1[i].to);
    }

}



void solve() {
    cin>>n>>m;
    init(h,color,n);
    for (int i=0;i<m;++i) {
        int a,b,w;
        cin>>a>>b;
        add(a,b,w);
        add(b,a,w);
    }
    for (int i=1;i<=n;++i) {
        if (color[i]==-1) {
            cnt++;
            dfs(i);
        }

    }
    cout<<cnt-1<<endl;



}

int main() {
    js;
    int T=1;
    //cin>>T;
    while (T--) {solve();}
    return 0;
}

