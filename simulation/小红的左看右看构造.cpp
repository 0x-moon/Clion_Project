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
typedef long long ll;typedef pair<int,int> PII;typedef priority_queue<int,vector<int>,greater<int>> pqIG;
const int INF=0x3f3f3f3f;const int mod=1e9+7;const int N=2e5+10;

int x,y,n,idx=1;
vector<int> ax,ay;

void solve() {
    cin>>x>>y>>n;
    rep(i,0,x) {
        int x;cin>>x;
        ax.push_back(x);
    }
    rep(i,0,y) {
        int x;cin>>x;
        ay.push_back(x);
    }
    for (int i=ay.size()-1;i>=0;--i) {
        auto it=upper_bound(all(ax),ay[i]);
        if (*it==ax[i])continue;
        if (it==ax.end()) {
            ax.push_back(ay[i]);
        }
        else ax.insert(it+1,ay[i]);
    }
    for (int i=0;i<n;++i) {
        cout<<ax[i]<<endl;
    }

}

int main() {
    js;
    int T=1;
    //cin>>T;
    while (T--) {solve();}
    return 0;
}

