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
const int N=1e5+10;


int n,m;
int a[N];
struct Edge {
    int to;
    int weight;
    int next;
}edge[N*2];
int idx=0,h[N];
int cnt=0,ans;
bool st[N]={0};
void init(int h[],int n) {
    for (int i=1;i<=n;++i) {
        h[i]=-1;
    }
}
void add(int a,int b,int w=1) {//用idx表示边节点编号
    edge[idx].to=b;edge[idx].weight=w;edge[idx].next=h[a];h[a]=idx++;
}
int dfs(int u) {
    if (u==n) {
        return u;
    }
    ans=max(ans,u);
    for (int i=h[u];i!=-1;i=edge[i].next) {
        int t=dfs(edge[i].to);
        ans=max(ans,t);
    }
    return ans;
}



void solve() {
    cin >> n >> m;
    init(h, n);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        add(u, v);
    }
    for (int i = 1; i <= n; ++i) {
        memset(st, 0, sizeof st); // 正确重置
        ans = 0;                  // 每次重置最大值
        cout << dfs(i) << ' ';
    }
    cout << endl;
}

int main() {
    js;
    int T=1;
    //cin>>T;
    while (T--) {solve();}
    return 0;
}

