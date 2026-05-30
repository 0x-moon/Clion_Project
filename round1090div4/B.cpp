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
const int INF=0x3f3f3f3f;const int mod=1e9+7;
const int N=1e5+10;


int n;
int a[N];

void solve() {
    int ans=0,maxt=-100;
    for (int i=0;i<7;++i) {
        int x;cin>>x;
        if (maxt<x) {
            maxt=x;
        }
        ans-=x;
    }
    cout<<ans+2*maxt<<endl;


}

int main() {
    js;
    int T=1;
    cin>>T;
    while (T--) {solve();}
    return 0;
}

