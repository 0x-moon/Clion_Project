#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define js ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define endl '\n'
typedef long long ll;typedef pair<int,int> PII;
const int inf=0x3f3f3f3f;const int mod=1e9+7;
const int N=1e5+10;

int n,x;


void solve() {
    cin>>n>>x;
    unordered_map<int,int>h;
    for (int i=0;i<n;++i) {
        int c; cin>>c;
        if (h.find(c)==h.end()) {
            h[c]=1;
        }
        else {
            h[c]++;
        }
    }
    int ans=n;
    for (auto &c:h) {
        if (c.second>x) {
            ans-=c.second;
        }
    }
    cout<<ans<<endl;
}

int main() {
    js;
    int T=1;
    cin>>T;
    while (T--) {solve();}
    return 0;
}


