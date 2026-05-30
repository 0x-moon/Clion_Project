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
int dist[N];

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


int dij(int bx, int ex, int lim) {
    for(int i=1; i<=n; ++i) dist[i]=inf;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    dist[bx]=0;
    q.push({0, bx});
    while (!q.empty()) {
        auto it = q.top();
        q.pop();
        int tar=it.second, weight=it.first;
        if(weight > dist[tar]) continue;

        for (int i=h[tar]; i!=-1; i=edge[i].next){
            int j=edge[i].to;
            int real_hg = (edge[i].hg == -1) ? inf : edge[i].hg;
            if (real_hg >= lim) {
                if (dist[tar] + edge[i].weight < dist[j]) {
                    dist[j] = dist[tar] + edge[i].weight;
                    q.push({dist[j], j});
                }
            }
        }
    }
    return dist[ex];
}

void solve() {
    while(cin>>n>>m) {
        if (n==0&&m==0)break;
        init(n);
        int max_r = 0;
        for (int i=0; i<m; ++i) {
            int a, b, hg, w;
            cin>>a>>b>>hg>>w;
            add(a, b, hg, w);
            add(b, a, hg, w);
            if(hg != -1) max_r = max(max_r, hg);
        }
        int bx, ex, lim;
        cin>>bx>>ex>>lim;

        int l=0, r=lim, ans_h=-1, ans_d=-1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int ret = dij(bx, ex, mid);
            if (ret != inf) {
                ans_h = mid;
                ans_d = ret;
                l = mid+1 ;
            } else {
                r = mid-1;
            }
        }
        if (t > 0) cout << endl;
        cout << "Case " << ++t << ":" << endl;
        if (ans_h == -1) {
            cout << "cannot reach destination" << endl;
        } else {
            cout << "maximum height = " << ans_h << endl;
            cout << "length of shortest route = " << ans_d << endl;
        }
    }
}

int main() {
    js;
    solve();
    return 0;
}