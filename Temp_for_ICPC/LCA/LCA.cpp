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

#define all(x) (x).begin(), (x).end()
#define js ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define endl '\n'
typedef long long ll;typedef pair<int,int> PII;typedef priority_queue<int,vector<int>,greater<int>> pq;
const int inf=0x3f3f3f3f;const int mod=1e9+7;
const int N=1e4+10,D=18,M=N*2;


int n;
int f[N][D];
int e[M],ne[M],h[N],idx;
int dep[N];
void init(int n) {
    idx=0;
    for (int i=0;i<=n;++i) {
        h[i]=-1;
        dep[i]=inf;
        for (int j=0;j<18;++j) {
            f[i][j]=0;
        }
    }
}
void bfs(int root) {
    dep[0]=0,dep[root]=1;
    deque<int> q;
    q.push_back(root);
    while (!q.empty()) {
        int t=q.front();
        q.pop_front();
        for (int i=h[t];i!=-1;i=ne[i]) {
            int j=e[i];
            if (dep[t]+1<dep[j]) {
                dep[j]=dep[t]+1;
                q.push_back(j);
                f[j][0]=t;
                for (int k=1;k<18;++k) {
                    f[j][k]=f[f[j][k-1]][k-1];
                }
            }
        }
    }
}
int lca(int a,int b) {
    if (dep[a]>dep[b])return lca(b,a);
    for (int i=17;i>=0;--i) {
        if (dep[f[a][i]]>=dep[b]) {
            a=f[a][i];
        }
    }
    if (a==b)return a;
    for (int i=17;i>=0;--i) {
        if (f[a][i]!=f[b][i]) {
            a=f[a][i];
            b=f[b][i];
        }
    }
    return f[a][0];
}
void solve() {
    cin>>n;



}

int main() {
    js;
    int T=1;
    //cin>>T;
    while (T--) {solve();}
    return 0;
}

