#include<bits/stdc++.h>

using namespace std;
#define int long long
#define all(x) (x).begin(), (x).end()
#define js ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define endl '\n'
typedef long long ll;typedef pair<int,int> PII;
const int inf=0x3f3f3f3f;const int mod=1e9+7;
const int N=2e5+10;


int n;

bool cmp(int a,int b) {
    return a>b;
}
void solve() {
    cin>>n;
    vector <int> a,w;
    unordered_map<int,int> h;
    for (int i=0;i<n;++i) {
        int x;cin>>x;
        if (h.find(x)!=h.end()) {
            w.push_back(x);
        }else {
            a.push_back(x);
            h[x]=1;
        }
    }
    set<int> s;
    for (int i=0;i<=n+1;++i) {
        s.insert(i);
    }
    int t=0;
    sort(a.begin(),a.end());
    auto it=a.back();
    a.pop_back();
    a.insert(a.begin(),it);
    for (auto &x:w) {
        a.push_back(x);
    }
    for (int i=0;i<n;++i) {
        s.erase(a[i]);
        t+=*s.begin()+a[0];
    }
    cout<<t<<endl;
}

signed main() {
    js;
    int T=1;
    cin>>T;
    while (T--) {solve();}
    return 0;
}

