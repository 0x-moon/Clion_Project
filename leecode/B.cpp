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
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define all(x) (x).begin(), (x).end()
#define js ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
typedef long long ll;typedef pair<int,int> PII;typedef priority_queue<PII,vector<PII>,greater<PII>> PQ;
const int INF=0x3f3f3f3f;const int MOD=1e9+7;const int N=2e5+10;


int n;
int a[N];

void solve() {
    cin>>n;
    PQ pq;
    rep(i,0,n) {
        cin>>a[i];
        pq.push({a[i],i});

    }
    for (int i=0;i<3;++i) {
        cout<<pq.top().second+1<< ' ';
        pq.pop();
    }



}

int main() {
    js;
    int T=1;
    //cin>>T;
    while (T--) {solve();}
    return 0;
}
