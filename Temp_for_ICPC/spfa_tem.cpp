//
// Created by 34914 on 2026/4/15.
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>

using namespace std;
#define js ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define endl '\n'
typedef pair<int,int> PII;
const int inf=0x3f3f3f3f;
const int N=1e5+10;

int n,m;
struct Edge {
    int to;
    int weight;
    int next;
    int hg;
}edge[N*2];
int idx=0, h[N], t=0;
int dist[N],st[N]={0};

void init(int n) {
    idx=0;
    for (int i=1;i<=n;++i) {
        h[i]=-1;
    }
}

void add(int a,int b,int hg,int w) {
    edge[idx].to=b;
    edge[idx].weight=w;
    edge[idx].hg=hg;
    edge[idx].next=h[a];
    h[a]=idx++;
}


int spfa() {
    for (int i=1;i<=n;++i)dist[i]=-inf;
    deque<int> q;
    for (int i=1;i<=n;++i) {
        q.push_back(i);
        st[i]=1;
    }
    while (!q.empty()) {
        auto t=q.front();
        q.pop_front();
        st[t]=false;
        for (int i=h[t];i!=-1;i=edge[i].next) {
            int j=edge[i].to;
            if (dist[j]<dist[t]+edge[i].weight) {
                dist[j]=dist[t]+edge[i].weight;
                if (st[j]==0) {
                    q.push_back(j);
                    st[j]=1;
                }
            }
        }
    }

}

void solve() {
    while(cin>>n>>m) {


    }
}

int main() {
    js;
    solve();
    return 0;
}